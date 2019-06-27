#pragma once

struct SDL_Window;
struct SDL_Surface;

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
	bool LoadMedia();
	bool InitImageExt();

	SDL_Window* m_window;
	SDL_Surface* m_mediaSurface;
};

}