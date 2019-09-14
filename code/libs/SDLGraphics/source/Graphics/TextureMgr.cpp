#include "SDL/Graphics/TextureMgr.h"
#include "App/Identifiers.h"

#include "SDL/Graphics/Renderer.h"
#include "Texture.h"

#include "cpp-utils/Assert.h"

#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#	include <SDL.h>
#	include <SDL_image.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include <type_traits>



namespace sdl
{
namespace graphics
{

TextureMgr::TextureMgr(sdl::graphics::Renderer& i_renderer)
	: m_renderer(i_renderer)
{
	InitImageExt();
	m_renderer.SetTextureMgr(this);
}

TextureMgr::~TextureMgr()
{
	m_renderer.SetTextureMgr(nullptr);
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

		const sdl::graphics::Texture* prevTex = _FindTextureById(textureId);
		DB_ASSERT_MSG(prevTex == nullptr, "Texture at path " << i_path << " was already created.");
		if ( prevTex == nullptr)
		{
			m_textures.emplace(textureId, std::move(texture));
		}
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
