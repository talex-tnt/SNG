#pragma once
#include "App/Graphics/ITexture.h"
#include <string>

struct SDL_Renderer;
struct SDL_Texture;
namespace sdl
{
namespace graphics
{

class Texture : public app::graphics::ITexture
{
public:
	Texture(const std::string& i_path, SDL_Renderer& i_renderer);
	~Texture() = default;

	Texture(const Texture&) = delete;
	Texture(Texture&&) = delete;

	Texture& operator=(const Texture&) = delete;
	Texture& operator=(Texture&&) = delete;


	void Render(int x, int y) const override;

private:
	SDL_Renderer& m_renderer;
	SDL_Texture* m_texture;
};

}
}