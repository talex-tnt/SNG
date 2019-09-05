#include "App/AppBase.h"
#include "App/UI/IWindow.h"

#include "cpp-utils/Assert.h"

namespace app
{ 

AppBase::AppBase() 
	: m_quit(false) 
{
	
};

AppBase::~AppBase() = default;

bool AppBase::Init()
{
	if ( OnInit() )
	{
		m_window = std::move(CreateWindow());
		return m_window != nullptr;
	}
	return false;
}

void AppBase::Run()
{
	while ( !m_quit )
	{
		ProcessEvents();
		m_window->Update();
		m_window->Render();
	}
}


void AppBase::OnEvent(events::EventType i_eventType)
{
	switch ( i_eventType )
	{
	case events::EventType::k_quit:
	m_quit = true;
	break;
	}
}

void AppBase::OnEvent(const events::KeyDownEvent& i_event)
{
	std::cout << i_event << std::endl;
}

}
