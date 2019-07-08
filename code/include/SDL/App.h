#pragma once
#include "App/IApp.h"
#include "App/AppBase.h"

union SDL_Event;
namespace sdl
{
class IUIFactory;
class App : public app::AppBase
{
public:
	App();
	~App() override;

	App(const App&) = delete;
	App(App&&) = delete;

	App& operator=(const App&) = delete;
	App& operator=(App&&) = delete;

protected:
	bool OnInit() override;
	void ProcessEvents() override;

	std::unique_ptr<app::ui::IWindow> CreateWindow() const override;

private:
	void OnEvent(const SDL_Event& e);
};

}