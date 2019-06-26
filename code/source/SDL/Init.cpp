#include "SDL/Init.h"
#include "SDL.h"
#include <iostream>
#include "cpp-utils/Assert.h"

namespace sdl
{ 
Init::Init()
{ 
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		DB_ASSERT_MSG(false, SDL_GetError());
	}
}

Init::~Init()
{ 
	SDL_Quit();
}
}
