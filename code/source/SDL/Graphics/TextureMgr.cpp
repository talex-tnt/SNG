#include "SDL/Graphics/TextureMgr.h"

#include "App/Identifiers.h"
#include "App/Graphics/ITexture.h"

#include "SDL/Graphics/Renderer.h"
#include "SDL/Graphics/Texture.h"

#include "cpp-utils/Assert.h"

#include "SDL.h"
#include <SDL_image.h>
#include <type_traits>



namespace sdl
{
namespace graphics
{

TextureMgr::TextureMgr(sdl::graphics::Renderer& i_renderer)
	: m_renderer(i_renderer)
{
	InitImageExt();

	const TexturePath texturePath("images/SDL_Logo.png");
	TextureId texture = CreateTexture(texturePath);
}

const sdl::graphics::Texture* TextureMgr::_FindTextureById(TextureId i_textureId) const
{
	auto it = m_textures.find(i_textureId);
	if ( it != m_textures.end() )
	{
		return it->second.get();
	}
	return nullptr;
}

sdl::graphics::Texture* TextureMgr::_FindTextureById(TextureId i_textureId)
{
	const TextureMgr& const_this = static_cast< const TextureMgr& >( *this );
	const sdl::graphics::Texture* const_text = const_this._FindTextureById(i_textureId);
	return const_cast< sdl::graphics::Texture * >( const_text );
}

app::graphics::ITexture* TextureMgr::FindTextureById(TextureId i_textureId)
{
	return _FindTextureById(i_textureId);
}

const app::graphics::ITexture* TextureMgr::FindTextureById(TextureId i_textureId) const
{
	return _FindTextureById(i_textureId);
}

TextureId TextureMgr::CreateTexture(TexturePath i_path)
{
	TextureId textureId;
	SDL_Renderer* renderer = m_renderer.GetSDLRenderer();
	TexturePtr texture = std::make_unique<sdl::graphics::Texture>(i_path, *renderer);
	
	DB_ASSERT_MSG(texture->IsValid(), "Couldn't create the texture at path " << i_path);
	if (texture->IsValid())
	{
		const std::size_t hash = std::hash<TexturePath::ValueType> {}( i_path.GetValue() );
		textureId = TextureId(hash);
		m_textures.emplace(textureId, std::move(texture));
	}
	return textureId;
}



bool TextureMgr::InitImageExt()
{
	const int imgFlags = IMG_INIT_PNG;
	const bool result = ( IMG_Init(imgFlags) & imgFlags );
	DB_ASSERT_MSG(result, SDL_GetError());
	return result;
}
} // namespace graphics
} // namespace sdl
