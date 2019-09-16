#include "SDL/Graphics/OpenGL/TextureMgr.h"
#include "SDL/Graphics/OpenGL/Renderer.h"

#include "App/Identifiers.h"

#include "Texture.h"

#include "cpp-utils/Assert.h"

#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#	include <SDL.h>
#	include <SDL_image.h>
#	include <SDL_opengl.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include <type_traits>

namespace sdl
{
namespace graphics
{
namespace opengl
{

TextureMgr::TextureMgr(Renderer& i_renderer)
	: m_renderer(i_renderer)
{
	InitImageExt();
	glEnable(GL_TEXTURE_2D);
	m_renderer.SetTextureMgr(this);
}

TextureMgr::~TextureMgr()
{
	m_renderer.SetTextureMgr(nullptr);
}

const Texture* TextureMgr::FindTextureById(TextureId i_textureId) const
{
	auto it = m_textures.find(i_textureId);
	if ( it != m_textures.end() )
	{
		return it->second.get();
	}
	return nullptr;
}

Texture* TextureMgr::FindTextureById(TextureId i_textureId)
{
	const TextureMgr& const_this = static_cast< const TextureMgr& >( *this );
	const Texture* const_text = const_this.FindTextureById(i_textureId);
	return const_cast< Texture * >( const_text );
}

TextureId TextureMgr::CreateTexture(TexturePath i_path)
{
	TextureId textureId;
	TexturePtr texture = std::make_unique<Texture>(i_path);

	DB_ASSERT_MSG(texture->IsValid(), "Couldn't create the texture at path " << i_path);
	if ( texture->IsValid() )
	{
		const std::size_t hash = std::hash<TexturePath::ValueType> {}( i_path.GetValue() );
		textureId = TextureId(hash);

		const Texture* prevTex = FindTextureById(textureId);
		DB_ASSERT_MSG(prevTex == nullptr, "Texture at path " << i_path << " was already created.");
		if ( prevTex == nullptr )
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

} // namespace opengl
} // namespace graphics
} // namespace sdl
