#include "App/AppBase.h"
#include "App/IAppDelegate.h"
#include "App/Interfaces/Graphics/IRenderer.h"

#include "cpp-utils/Assert.h"
#include <chrono>

namespace
{
std::chrono::milliseconds GetElapsed(std::chrono::steady_clock::time_point& lastTime)
{
	std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
	std::chrono::steady_clock::duration elapsed = current - lastTime;
	lastTime = current;
	return std::chrono::duration_cast< std::chrono::milliseconds >( elapsed );
}
}

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
		return i_appDelegate.OnInit();
	}
	return false;
}

void AppBase::Run(app::graphics::IRenderer& i_renderer)
{
	DB_ASSERT_MSG(m_appDelegate, "Please call Init(..) first");
	std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
	while ( !m_quit )
	{
		const std::chrono::milliseconds elapsedTime = GetElapsed(lastTime);
		ProcessEvents();
		m_appDelegate->OnUpdate(elapsedTime);
		i_renderer.BeginRendering();
		m_appDelegate->OnRender();
		i_renderer.EndRendering();
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
