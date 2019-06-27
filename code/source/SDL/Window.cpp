#include "SDL/Window.h"
#include "cpp-utils/Assert.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

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

		if ( InitImageExt() && LoadMedia() )
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

bool Window::InitImageExt()
{
	const int imgFlags = IMG_INIT_PNG;
	const bool result = (IMG_Init(imgFlags) & imgFlags );
	DB_ASSERT_MSG(result, SDL_GetError());
	return result;
}

bool Window::LoadMedia()
{ 
	bool result = true;
	m_mediaSurface = IMG_Load( "images/SDL_Logo.png" );
	if( !m_mediaSurface ) 
	{
		result = false;
	} 
	DB_ASSERT_MSG(result,  SDL_GetError());
	return result; 
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
