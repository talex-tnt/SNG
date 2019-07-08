#pragma once
#include "App/Graphics/ITexture.h"
#include <string>
#include <functional>

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

	using TextureUnPtr = std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture*)>>;
	TextureUnPtr m_texture;

};

}
}