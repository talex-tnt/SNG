#pragma once
#include "App/IApp.h"
#include <memory>

namespace app
{
class IUIFactory;
namespace ui
{
class IWindow;
}

class AppBase : public app::IApp
{
protected:
	AppBase();
	~AppBase();

public:
	bool Init() override final; 
	void Run() override final;
	void Quit();

protected:
	virtual bool OnInit() = 0;
	virtual void ProcessEvents() = 0;

	std::unique_ptr<app::IUIFactory> m_uiFactory;
	std::unique_ptr<app::ui::IWindow> m_window;
	bool m_quit;
};

}