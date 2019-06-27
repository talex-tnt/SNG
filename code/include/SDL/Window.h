#pragma once

struct SDL_Window;
struct SDL_Surface;
union SDL_Event;

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

	void Show();
private:
	bool LoadMedia();
	bool InitImageExt();
	void OnEvent(const SDL_Event& e);
	void Render();

	SDL_Window* m_window;
	SDL_Surface* m_screenSurface;
	SDL_Surface* m_mediaSurface;

	bool m_quit;
};

}