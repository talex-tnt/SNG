#include "SDL/App.h"
#include "SDL.h"
#include <iostream>
#include "cpp-utils/Assert.h"
#include "cpp-utils/Log.h"
#include "UI/Window.h"
#include "App/Events.h"
#include "App/AppContext.h"

namespace sdl
{ 
App::App() = default;

App::~App()
{
	SDL_Quit();
}

bool App::OnInit()
{
	bool initialized = false;
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		DB_LOG("SDL_Init Error: " << SDL_GetError());
		DB_ASSERT_MSG(false, SDL_GetError());
		initialized = false;
	}
	else
	{
		m_window = std::make_unique<sdl::ui::Window>();
		initialized = true;
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

std::unique_ptr<app::AppContext> App::CreateAppContext() const
{
	app::graphics::IRenderer* renderer = m_window->GetRenderer();
	app::graphics::ITextureMgr* textureMgr = m_window->GetTextureMgr();
	if (renderer && textureMgr)
	{
		return std::make_unique<app::AppContext>(*renderer, *textureMgr);
	}
	return nullptr;
}

}
