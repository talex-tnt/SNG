#pragma once
#include "SDL/IAppDelegate.h"
#include "../Game/Game.h"

namespace sdl
{
namespace ui 
{
class IWindowProvider;
}
}

namespace sng
{
class GameContext;
class SDLAppProxy : public sdl::IAppDelegate
{
public:
	~SDLAppProxy();
	bool Start();
	bool OnInit(sdl::ui::IWindowProvider&) override;
	
private:
	std::unique_ptr<GameContext> CreateAppContext(sdl::ui::IWindowProvider& i_windowProvider);
private:
	Game m_game;
};
}