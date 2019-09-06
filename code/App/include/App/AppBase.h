#pragma once
#include "App/IApp.h"
#include "Events.h"
#include <memory>

namespace app
{
class IAppDelegate;
class AppContext;
class AppBase : public app::IApp
{
protected:
	AppBase();
	~AppBase();

public:
	bool Init(IAppDelegate& i_appDelegate) override final;
	void Run() override final;
	
	void OnEvent(events::EventType i_eventType);
	void OnEvent(const events::KeyDownEvent& i_event);

protected:
	virtual bool OnInit() = 0;
	virtual void ProcessEvents() = 0;

	std::unique_ptr<app::AppContext> m_context;
	IAppDelegate* m_appDelegate;
	bool m_quit;
};

}