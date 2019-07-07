#include "SDL/Graphics/TextureMgr.h"
#include "cpp-utils/Assert.h"
#include "SDL/Graphics/Renderer.h"
#include "SDL/Graphics/Texture.h"
#include "App/Graphics/ITexture.h"

#include "SDL.h"
#include <SDL_image.h>



namespace sdl
{
namespace graphics
{

TextureMgr::TextureMgr(sdl::graphics::Renderer& i_renderer)
	: m_renderer(i_renderer)
	, m_texture()
{
	InitImageExt();
	SDL_Renderer* renderer = m_renderer.GetSDLRenderer();
	m_texture = std::make_unique<sdl::graphics::Texture>("images/SDL_Logo.png", *renderer);
}

app::graphics::ITexture* TextureMgr::GetTexture()
{
	const TextureMgr& const_this = static_cast< const TextureMgr& >( *this );
	const app::graphics::ITexture* const_text = const_this.GetTexture();
	return const_cast< app::graphics::ITexture *>( const_text );
}

const app::graphics::ITexture* TextureMgr::GetTexture() const
{
	DB_ASSERT_MSG(m_texture, "Texture is null..");
	return m_texture ? m_texture.get() : nullptr;
}

bool TextureMgr::InitImageExt()
{
	const int imgFlags = IMG_INIT_PNG;
	const bool result = ( IMG_Init(imgFlags) & imgFlags );
	DB_ASSERT_MSG(result, SDL_GetError());
	return result;
}
} //namespace graphics
} // namespace sdl
