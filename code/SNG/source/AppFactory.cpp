#include "SDL/App.h"
#include "AppFactory.h"
#include "SDL/App.h"

namespace sng
{
std::unique_ptr<app::IApp> AppFactory::CreateApp()
{
	return std::make_unique<sdl::App>();
}
}
