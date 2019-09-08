#pragma once
#include "App/IApp.h"
#include "App/AppBase.h"

namespace app
{
class AppContext;
}

union SDL_Event;
namespace sdl
{
namespace ui
{
class Window;
class IWindowProvider;
}

class IAppContextFactory
{
public:
	virtual ~IAppContextFactory() = default;
	virtual std::unique_ptr<app::AppContext> CreateAppContext(sdl::ui::IWindowProvider& i_windowProvider) = 0;
};

class App : public app::AppBase
{
public:
	App(std::unique_ptr<IAppContextFactory> i_appContextDelegate);
	~App() override;

	App(const App&) = delete;
	App(App&&) = delete;

	App& operator=(const App&) = delete;
	App& operator=(App&&) = delete;

protected:
	bool OnInit() override;
	void ProcessEvents() override;
	std::unique_ptr<app::AppContext> CreateAppContext() const override;

private:
	void _OnEvent(const SDL_Event& e);
	std::unique_ptr<sdl::ui::Window> m_window;
	std::unique_ptr<IAppContextFactory> m_appContextDelegate;
};

}