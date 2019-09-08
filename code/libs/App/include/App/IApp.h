#pragma once
#include <memory>

namespace app
{
class AppContext;
class IAppDelegate;

namespace ui
{
class IWindow;
}
class IApp
{
public:
	virtual ~IApp() = default;
	virtual bool Init(IAppDelegate& i_appDelegate) = 0;
	virtual void Run() = 0;

protected:
	virtual std::unique_ptr<app::AppContext> CreateAppContext() const = 0;
};

}