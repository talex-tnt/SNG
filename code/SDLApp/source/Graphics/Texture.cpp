#include "SDL/Graphics/Texture.h"
#include "cpp-utils/Assert.h"

#include "SDL.h"
#include <SDL_image.h>

namespace
{
SDL_Texture* LoadTexture(TexturePath path, SDL_Renderer* renderer)
{
	SDL_Texture* newTexture = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(path.GetValue().c_str());
	DB_ASSERT_MSG(loadedSurface, "Unable to load image " << path.GetValue().c_str() << "! SDL_image Error: " << IMG_GetError());

	if ( loadedSurface )
	{
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		DB_ASSERT_MSG(newTexture, "Unable to create texture from " << path.GetValue().c_str() << "! SDL Error :" << SDL_GetError());

		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}
}

namespace sdl
{
namespace graphics
{

Texture::Texture(const TexturePath& i_path, SDL_Renderer& i_renderer)
	: m_renderer(i_renderer)
	, m_texture(
		LoadTexture(i_path, &m_renderer),
		[] (SDL_Texture* tex) { SDL_DestroyTexture(tex); })
{
	DB_ASSERT_MSG(m_texture, "Unable to create texture with path " << i_path);
}


void Texture::Render(int x, int y) const
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(m_texture.get(), NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(&m_renderer, m_texture.get(), NULL, &dst);
}

bool Texture::IsValid() const
{
	return m_texture != nullptr;
}

} //namespace graphics
} // namespace sdl
