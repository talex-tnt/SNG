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

namespace app
{
namespace graphics
{
class IRenderer;
}
}

namespace sng
{
class GameContext;
class SDLAppProxy : public sdl::IAppDelegate
{
public:
	SDLAppProxy();
	~SDLAppProxy();
	bool Start();
	bool OnInit(sdl::ui::IWindowProvider&) override;
	
private:
	template<class RendererT, class TextureMgrT>
	std::unique_ptr<sng::GameContext> CreateGameContext(sdl::ui::IWindowProvider& i_windowProvider);

	app::graphics::IRenderer* m_renderer;
	Game m_game;
};
}