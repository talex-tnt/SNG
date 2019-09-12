#pragma once
#include "Events.h"
#include <memory>

namespace app
{
class IAppDelegate;
class AppBase
{
protected:
	AppBase();
	~AppBase();

public:
	bool Init(IAppDelegate& i_appDelegate);
	void Run();
	
	void OnEvent(events::EventType i_eventType);
	void OnEvent(const events::KeyDownEvent& i_event);

protected:
	virtual bool OnInit() = 0;
	virtual void ProcessEvents() = 0;

	IAppDelegate* m_appDelegate;
	bool m_quit;
};

}