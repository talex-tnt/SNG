#include "Init.h"
#include "SDL.h"
#include <iostream>

namespace sdl
{ 
Init::Init()
{ 
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
//		DB_ASSERT_MSG();
	}
}

Init::~Init()
{ 
	SDL_Quit();
}
}
