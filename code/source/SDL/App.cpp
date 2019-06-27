#include "SDL/App.h"
#include "SDL.h"
#include <iostream>
#include "cpp-utils/Assert.h"

namespace sdl
{ 

bool App::Init()
{
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
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
