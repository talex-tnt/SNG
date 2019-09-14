#pragma once
#include "App/Identifiers.h"
#include "SDL/UI/IWindowProvider.h"

#include <functional>
#include <memory>

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
class Window final: public IWindowProvider
{
public:
	Window();
	~Window();

	Window(const Window&) = delete;
	Window(Window&&) = delete;

	Window& operator=(const Window&) = delete;
	Window& operator=(Window&&) = delete;

	SDL_Window* GetSDLWindow() override;
	const SDL_Window* GetSDLWindow() const override;

private:

	using WindowUniquePtr = std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>>;
	WindowUniquePtr m_window;
};

}
}