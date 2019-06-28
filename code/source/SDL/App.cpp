#include "SDL/App.h"
#include "SDL.h"
#include <iostream>
#include "cpp-utils/Assert.h"
#include "cpp-utils/Log.h"

namespace sdl
{ 

bool App::Init()
{
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		DB_MSG("SDL_Init Error: " << SDL_GetError());
		DB_ASSERT_MSG(false, SDL_GetError());
		m_initialized = false;
	}
	else
	{
		m_initialized = true;
	}
	return m_initialized;
}

App::~App()
{ 
	SDL_Quit();
}

App::App() 
	: m_initialized(false)
{
	
}

}
