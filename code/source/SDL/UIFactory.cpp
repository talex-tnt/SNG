#include "SDL/UIFactory.h"
#include "SDL/UI/Window.h"

namespace sdl
{

UIFactory::~UIFactory() = default;

std::unique_ptr<app::ui::IWindow> UIFactory::CreateWindow() const
{
	return std::make_unique<sdl::ui::Window>();
}

}
