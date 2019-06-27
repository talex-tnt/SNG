#pragma once

struct SDL_Window;

namespace sdl
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

private:
	SDL_Window *m_window;
};

}