#include "SDL/Window.h"
#include "SDL.h"
#include <iostream>
#include "cpp-utils/Assert.h"

namespace sdl
{

Window::Window() : m_window(nullptr), m_mediaSurface(nullptr)
{
	m_window = SDL_CreateWindow(
		"SDL2Test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		0
	);

	if ( m_window )
	{
		SDL_Renderer* renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		if (LoadMedia())
		{
			SDL_Surface* screenSurface = SDL_GetWindowSurface(m_window);
			SDL_BlitSurface(m_mediaSurface, NULL, screenSurface, NULL);
			SDL_UpdateWindowSurface(m_window);
		}

		SDL_Delay(3000);
	}
	else
	{
		DB_ASSERT_MSG(false,  SDL_GetError());
	}
}

bool Window::LoadMedia()
{ 
	bool success = true;
	m_mediaSurface = SDL_LoadBMP( "images/Placeholder.bmp" ); 
	if( !m_mediaSurface ) 
	{
		success = false;
	} 
	DB_ASSERT_MSG(success,  SDL_GetError());
	return success; 
}

Window::~Window()
{
	if (m_mediaSurface)
	{
		SDL_FreeSurface(m_mediaSurface);
	}
	if ( m_window )
	{
		SDL_DestroyWindow(m_window);
	}
}
}
