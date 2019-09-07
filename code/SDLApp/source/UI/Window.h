#pragma once
#include "App/Identifiers.h"
#include <functional>
#include <memory>

struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;
struct SDL_Texture;
union SDL_Event;

namespace app
{
namespace graphics
{
class IRenderer;
class ITextureMgr;
}
}

namespace sdl
{
namespace graphics
{
class Renderer;
class TextureMgr;
}

namespace ui
{

class Window
{
public:
	Window();
	~Window();

	Window(const Window&) = delete;
	Window(Window&&) = delete;

	Window& operator=(const Window&) = delete;
	Window& operator=(Window&&) = delete;

	SDL_Window* GetSDLWindow();
	const SDL_Window* GetSDLWindow() const; 

	const app::graphics::IRenderer* GetRenderer() const;
	const app::graphics::ITextureMgr* GetTextureMgr() const;
	app::graphics::IRenderer* GetRenderer();
	app::graphics::ITextureMgr* GetTextureMgr();

private:

	using WindowUniquePtr = std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>>;
	WindowUniquePtr m_window;

	std::unique_ptr<sdl::graphics::Renderer> m_renderer;
	std::unique_ptr<sdl::graphics::TextureMgr> m_textureMgr;
};

}
}