#pragma once
#include "App/AppBase.h"
#include "IAppDelegate.h"

union SDL_Event;
namespace sdl
{
namespace ui
{
class Window;
}

class App : public app::AppBase
{
public:
	App();
	~App();

	App(const App&) = delete;
	App(App&&) = delete;

	App& operator=(const App&) = delete;
	App& operator=(App&&) = delete;

	void SetDelegate(IAppDelegate* i_delegate);

protected:
	bool OnInit() override;
	void ProcessEvents() override;

private:
	void _OnEvent(const SDL_Event& e);
	std::unique_ptr<sdl::ui::Window> m_window;
	IAppDelegate* m_delegate;
};

}