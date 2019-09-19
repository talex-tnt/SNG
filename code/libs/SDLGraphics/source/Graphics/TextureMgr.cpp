#include "SDL/Graphics/TextureMgr.h"
#include "App/Identifiers.h"

#include "SDL/Graphics/Renderer.h"
#include "SDL/Graphics/SurfaceMgr.h"
#include "Texture.h"


#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#	include <SDL.h>
#	include <SDL_image.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include "cpp-utils/Assert.h"
#include <type_traits>
#include "SDL/Graphics/SurfaceBase.h"

namespace sdl
{
namespace graphics
{

TextureMgr::TextureMgr(SurfaceMgr& i_surfaceMgr, Renderer& i_renderer)
	: m_renderer(i_renderer), m_surfaceMgr(i_surfaceMgr)
{
	InitImageExt();
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
	SDL_Renderer* renderer = m_renderer.GetSDLRenderer();
	TexturePtr texture = std::make_unique<Texture>(i_path, *renderer);
	
	DB_ASSERT_MSG(texture->IsValid(), "Couldn't create the texture at path " << i_path);
	if (texture->IsValid())
	{
		const std::size_t hash = std::hash<TexturePath::ValueType> {}( i_path.GetValue() );
		textureId = TextureId(hash);

		const Texture* prevTex = FindTextureById(textureId);
		DB_ASSERT_MSG(prevTex == nullptr, "Texture at path " << i_path << " was already created.");
		if ( prevTex == nullptr)
		{
			m_textures.emplace(textureId, std::move(texture));
		}
	}
	return textureId;
}

TextureId TextureMgr::CreateTexture(SurfaceId i_surfaceId)
{
	TextureId textureId;
	ISurface* surface = m_surfaceMgr.FindSurfaceById(i_surfaceId);
	DB_ASSERT_MSG(surface && surface->IsValid(), "Surface with id " << i_surfaceId << " was not found or isn't valid.");
	if (surface && surface->IsValid())
	{
		SDL_Renderer* renderer = m_renderer.GetSDLRenderer();
		TexturePtr texture = std::make_unique<Texture>(*surface, *renderer);

		DB_ASSERT_MSG(texture->IsValid(), "Couldn't create the texture from Surface with id " << surface->GetId());
		if ( texture->IsValid() )
		{
			textureId = TextureId(surface->GetId().GetValue());

			const Texture* prevTex = FindTextureById(textureId);
			DB_ASSERT_MSG(prevTex == nullptr, "Texture from Surface with id " << surface->GetId() << " was already created.");
			if ( prevTex == nullptr )
			{
				m_textures.emplace(textureId, std::move(texture));
			}
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
