#include "AppFactory.h"
#include "SDL/App.h"

namespace sng
{

AppFactory::~AppFactory() = default;

std::unique_ptr<app::IApp> AppFactory::CreateApp() const
{
	return std::make_unique<sdl::App>();
}

}
