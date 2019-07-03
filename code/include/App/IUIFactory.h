#pragma once
#include <memory>
#include "UI/IWindow.h"

namespace app
{
class IApp;
}
namespace app
{

class IUIFactory
{
public:
	virtual ~IUIFactory() = default;
	virtual std::unique_ptr<app::ui::IWindow> CreateWindow() const = 0;
};

}