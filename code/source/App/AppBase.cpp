#include "App/AppBase.h"
#include "cpp-utils/Assert.h"
#include "App/AppContext.h"
#include "App/IAppDelegate.h"

namespace app
{ 

AppBase::AppBase() 
	: m_quit(false) 
{
	
};

AppBase::~AppBase() = default;

bool AppBase::Init(IAppDelegate& i_appDelegate)
{
	m_appDelegate = &i_appDelegate;
	if ( OnInit() )
	{
		m_context = CreateAppContext();
		if (m_context)
		{
			i_appDelegate.OnInit(*m_context);
		}
		return m_context != nullptr;
	}
	return false;
}

void AppBase::Run()
{
	graphics::RenderContext& appContext = m_context->GetRenderContext();
	DB_ASSERT_MSG(m_appDelegate, "Please call Init(..) first");
	while ( !m_quit )
	{
		ProcessEvents();
		m_appDelegate->OnUpdate();
		m_appDelegate->OnRender(appContext);
		//m_window->Update();
		//m_window->Render();
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
