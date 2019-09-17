#pragma once
#include <string>
#include <functional>
#include "App/Identifiers.h"

struct SDL_Renderer;
struct SDL_Texture;
namespace sdl
{
namespace graphics
{
class ISurface;
class Texture
{
public:
	Texture(ISurface& i_surface, SDL_Renderer& i_renderer);
	Texture(const TexturePath& i_path, SDL_Renderer& i_renderer);
	~Texture() = default;

	Texture(const Texture&) = delete;
	Texture(Texture&&) = delete;

	Texture& operator=(const Texture&) = delete;
	Texture& operator=(Texture&&) = delete;


	void Render(int x, int y) const;
	bool IsValid() const;

private:
	SDL_Renderer& m_renderer;

	using TextureUnPtr = std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture*)>>;
	TextureUnPtr m_texture;

};

}
}