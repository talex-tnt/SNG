#pragma once
#include "App/Graphics/IRenderer.h"
#include <functional>
#include <memory>

struct SDL_Renderer;

namespace app
{
namespace graphics
{
class ITextureMgr;
}
}

namespace sdl
{
namespace ui
{
class Window;
}
namespace graphics
{

class Renderer : public app::graphics::IRenderer
{
public:
	Renderer(ui::Window& i_window);
	~Renderer();

	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;

	Renderer& operator=(const Renderer&) = delete;
	Renderer& operator=(Renderer&&) = delete;

	void Render(const app::graphics::ITexture& i_texture) const override;
	bool Init();

	const SDL_Renderer* GetSDLRenderer() const;
	SDL_Renderer* GetSDLRenderer();

private:
	using RendererUnPtr = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>>;
	RendererUnPtr m_renderer;
};

}
}