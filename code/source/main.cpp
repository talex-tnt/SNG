#include "SDL/App.h"
#include "SDL/Window.h"

int main(int argc, char *argv[])
{
	sdl::App sdlApp;
	if (sdlApp.Init())
	{
		sdl::Window window;
		window.Show();
	}
  return 0;
}