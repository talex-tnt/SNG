#include "SDL/Window.h"
#include "SDL.h"
#include <iostream>
#include "cpp-utils/Assert.h"

namespace sdl
{ 
Window::Window()
{ 
	m_window = SDL_CreateWindow(
		"SDL2Test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		0
	);

	SDL_Renderer *renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);
}

Window::~Window()
{ 
	SDL_DestroyWindow(m_window);

}
}
