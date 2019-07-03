#pragma once
#include <memory>
#include "App/IUIFactory.h"

namespace app
{
class IApp;
}
namespace sdl
{

class UIFactory : public app::IUIFactory
{
public:
	~UIFactory() override;
	std::unique_ptr<app::ui::IWindow> CreateWindow() const override;
};

}