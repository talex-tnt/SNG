#pragma once
#include "App/IApp.h"
#include "Events.h"
#include <memory>

namespace app
{
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
	
	void OnEvent(events::EventType i_eventType);
	void OnEvent(const events::KeyDownEvent& i_event);

protected:
	virtual bool OnInit() = 0;
	virtual void ProcessEvents() = 0;

	std::unique_ptr<app::ui::IWindow> m_window;
	bool m_quit;
};

}