#include "SDL/App.h"
#include "SDL/Window.h"
#include <iostream>

int main(int argc, char *argv[])
{
	sdl::App sdl;
	if (sdl.Init())
	{
		sdl::Window window;
	}
  return 0;
}