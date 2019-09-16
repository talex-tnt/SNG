#include "Window.h"
#include "cpp-utils/Assert.h"

#include "App/Interfaces/Graphics/ITextureMgr.h"
#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#include <SDL.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include <iostream>
#include <iosfwd>
#include <string>


namespace sdl
{
namespace ui
{

Window::Window(std::uint32_t i_flags)
	: m_window(
		SDL_CreateWindow(
			"SDL2Test",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			1280,
			1024,
			i_flags
		),
		[] (SDL_Window* win) { SDL_DestroyWindow(win); })
{
	if ( !m_window )
	{
		DB_ASSERT_MSG(false, SDL_GetError());
	}
}

Window::~Window() = default;


SDL_Window* Window::GetSDLWindow()
{
	return m_window ? m_window.get() : nullptr;
}

const SDL_Window* Window::GetSDLWindow() const
{
	return m_window ? m_window.get() : nullptr;
}

}
}
