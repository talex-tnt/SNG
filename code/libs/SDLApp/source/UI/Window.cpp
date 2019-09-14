#include "Window.h"
#include "cpp-utils/Assert.h"

#include "App/Graphics/ITextureMgr.h"
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

Window::Window()
	: m_window(
		SDL_CreateWindow(
			"SDL2Test",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			0
		),
		[] (SDL_Window* win) { SDL_DestroyWindow(win); })
{
	if ( m_window )
	{
#if false
		m_renderer = std::make_unique<sdl::graphics::Renderer>(*this);
		DB_ASSERT_MSG(m_renderer, "Renderer Not Initialized");
		if ( m_renderer )
		{
			sdl::graphics::Renderer* rend = m_renderer.get();
			m_textureMgr = std::make_unique<sdl::graphics::TextureMgr>(*rend);
		}
#endif
	}
	else
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
