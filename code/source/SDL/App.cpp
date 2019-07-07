#include "SDL/App.h"
#include "SDL.h"
#include <iostream>
#include "cpp-utils/Assert.h"
#include "cpp-utils/Log.h"
#include "SDL/UI/Window.h"
#include "SDL/UIFactory.h"

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
		DB_MSG("SDL_Init Error: " << SDL_GetError());
		DB_ASSERT_MSG(false, SDL_GetError());
		initialized = false;
	}
	else
	{
		// init more stuff here...
		initialized = true;
	}
	return initialized;
}

void App::ProcessEvents()
{
	SDL_Event e;
	while ( SDL_PollEvent(&e) != 0 )
	{
		OnEvent(e);
	}
}

void App::OnEvent(const SDL_Event& e)
{
	switch ( e.type )
	{
	case SDL_QUIT:
	{
		Quit();
	} break;
	//
	default:
	break;
	}
}

std::unique_ptr<app::IUIFactory> App::CreateUIFactory()
{
	return std::make_unique<sdl::UIFactory>();
}



}
