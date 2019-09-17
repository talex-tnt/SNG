#pragma once
struct SDL_Window;

namespace sdl
{
	namespace ui
	{
	class IWindow
	{
	public:
		virtual SDL_Window* GetSDLWindow() = 0;
		virtual const SDL_Window* GetSDLWindow() const = 0;

	protected:
		~IWindow() = default;
	};
	}
}