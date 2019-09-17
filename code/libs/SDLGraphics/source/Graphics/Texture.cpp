#include "Texture.h"
#include "cpp-utils/Assert.h"
#include "SDL/Graphics/ISurface.h"

#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#	include <SDL.h>
#	include <SDL_image.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

namespace
{

SDL_Texture* LoadTexture(SDL_Surface* loadedSurface, SDL_Renderer* renderer, const TexturePath& path = TexturePath(""))
{
	SDL_Texture* newTexture = nullptr;
	DB_ASSERT_MSG(loadedSurface, "Unable to load image " << path.GetValue().c_str() << "! SDL_image Error: " << IMG_GetError());
	if ( loadedSurface )
	{
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		DB_ASSERT_MSG(newTexture, "Unable to create texture from " << path.GetValue().c_str() << "! SDL Error :" << SDL_GetError());

		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

SDL_Texture* LoadTextureWithPath(const TexturePath& path, SDL_Renderer* renderer)
{
	return LoadTexture(IMG_Load(path.GetValue().c_str()), renderer, path);
}

}

namespace sdl
{
namespace graphics
{

Texture::Texture(const TexturePath& i_path, SDL_Renderer& i_renderer)
	: m_renderer(i_renderer)
	, m_texture(
		LoadTextureWithPath(i_path, &m_renderer),
		[] (SDL_Texture* tex) { SDL_DestroyTexture(tex); })
{
	DB_ASSERT_MSG(m_texture, "Unable to create texture with path " << i_path);
}


Texture::Texture(ISurface& i_surface, SDL_Renderer& i_renderer)
	: m_renderer(i_renderer)
	, m_texture(
		LoadTexture(i_surface.GetSDLSurface(), &m_renderer),
		[] (SDL_Texture* tex) { SDL_DestroyTexture(tex); })
{

}

void Texture::Render(int x, int y) const
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(m_texture.get(), nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(&m_renderer, m_texture.get(), nullptr, &dst);
}

bool Texture::IsValid() const
{
	return m_texture != nullptr;
}

} //namespace graphics
} // namespace sdl
