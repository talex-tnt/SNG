#pragma once
#include <memory>

namespace app
{
namespace ui
{
class IWindow;
}
class IApp
{
public:
	virtual ~IApp() = default;
	virtual bool Init() = 0;
	virtual void Run() = 0;

protected:
	virtual std::unique_ptr<app::ui::IWindow> CreateWindow() const = 0;

};

}