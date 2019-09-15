#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#	include <SDL.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include "SDL/App.h"
#include <iostream>
#include "cpp-utils/Assert.h"
#include "cpp-utils/Log.h"
#include "UI/Window.h"
#include "App/Events.h"

namespace {
static const  std::string k_opengl = "opengl";
}

namespace sdl
{ 
App::App() : m_delegate(nullptr), m_initFlags(InitFlag::k_none) { }

App::App(InitFlag i_initFlags) : m_delegate(nullptr), m_initFlags(i_initFlags)
{

}

App::~App()
{
	SDL_Quit();
}

void App::SetDelegate(IAppDelegate* i_delegate)
{
	m_delegate = i_delegate;
}

bool App::OnInit()
{
	bool initialized = false;
	std::uint32_t flags = 0u;
	switch ( m_initFlags )
	{
	case sdl::App::InitFlag::k_none: break;
	case sdl::App::InitFlag::k_openGL:
	flags = flags | SDL_WINDOW_OPENGL;
	break;
	}
	if ( SDL_Init(SDL_INIT_VIDEO | flags) < 0 )
	{
		DB_LOG("SDL_Init Error: " << SDL_GetError());
		DB_ASSERT_MSG(false, SDL_GetError());
		
		initialized = false;
	}
	else
	{
		if ( m_initFlags == sdl::App::InitFlag::k_openGL )
		{
			SDL_SetHint(SDL_HINT_RENDER_DRIVER, k_opengl.c_str());
		}
		m_window = std::make_unique<sdl::ui::Window>(flags);
		initialized = true;
		if (m_delegate)
		{
			m_delegate->OnInit(*m_window);
		}
	}
	return initialized;
}

void App::ProcessEvents()
{
	SDL_Event e;
	while ( SDL_PollEvent(&e) != 0 )
	{
		_OnEvent(e);
	}
}

void App::_OnEvent(const SDL_Event& e)
{
	switch ( e.type )
	{
	case SDL_QUIT:
	{
		OnEvent(app::events::EventType::k_quit);
	} break;
	case SDL_KEYDOWN:
	{
		using KeyDownEvent = app::events::KeyDownEvent;
		KeyDownEvent::KeycodeType key = KeyDownEvent::KeycodeType::k_down; // Fixme: use optional
		switch ( e.key.keysym.sym )
		{
		case SDLK_LEFT:
		{
			key = KeyDownEvent::KeycodeType::k_left;
		} break;
		case SDLK_RIGHT:
		{
			key = KeyDownEvent::KeycodeType::k_right;
		} break;		
		case SDLK_UP:
		{
			key = KeyDownEvent::KeycodeType::k_up;
		} break;		
		case SDLK_DOWN:
		{
			key = KeyDownEvent::KeycodeType::k_down;
		} break;		
		}
		OnEvent(KeyDownEvent(key));
	} break;
	//
	default:
	//DB_ASSERT_MSG(false, "Unhandled SDL Event: " + std::to_string(e.type));
	break;
	}
}

}
