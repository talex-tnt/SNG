#include "SDL/UI/Window.h"
#include "cpp-utils/Assert.h"

#include "SDL/Graphics/Renderer.h"
#include "SDL/Graphics/TextureMgr.h"
#include "App/Graphics/ITextureMgr.h"
#include <SDL.h>

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
		m_renderer = std::make_unique<sdl::graphics::Renderer>(*this);
		DB_ASSERT_MSG(m_renderer, "Renderer Not Initialized");
		if ( m_renderer )
		{
			sdl::graphics::Renderer* rend = m_renderer.get();
			m_textureMgr = std::make_unique<sdl::graphics::TextureMgr>(*rend);
		}
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

const app::graphics::IRenderer* Window::GetRenderer() const
{
	return m_renderer ? m_renderer.get() : nullptr;
}

app::graphics::IRenderer* Window::GetRenderer()
{
	return m_renderer ? m_renderer.get() : nullptr;
}

const app::graphics::ITextureMgr* Window::GetTextureMgr() const
{
	return m_textureMgr ? m_textureMgr.get() : nullptr;
}

app::graphics::ITextureMgr* Window::GetTextureMgr()
{
	return m_textureMgr ? m_textureMgr.get() : nullptr;
}

}
}
