#pragma once
#include "App/UI/IWindow.h"

struct SDL_Window;
struct SDL_Surface;
union SDL_Event;

namespace sdl
{
namespace ui
{

class Window : public app::ui::IWindow
{
public:
	Window();
	~Window() override;

	Window(const Window&) = delete;
	Window(Window&&) = delete;

	Window& operator=(const Window&) = delete;
	Window& operator=(Window&&) = delete;

private:
	bool LoadMedia();
	bool InitImageExt();

	void Render() const override;
	void Update() override;


	SDL_Window* m_window;
	SDL_Surface* m_screenSurface;
	SDL_Surface* m_mediaSurface;
};

}
}