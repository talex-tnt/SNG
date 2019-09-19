#pragma once
#include "SDL/IAppDelegate.h"
#include "../Game/Game.h"
#include "SDL/Graphics/SurfaceMgr.h"

namespace sdl
{
namespace ui 
{
class IWindow;
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
	bool OnInit(sdl::ui::IWindow&) override;
	
private:
	template<class RendererT, class TextureMgrT>
	std::unique_ptr<sng::GameContext> CreateGameContext(sdl::ui::IWindow& i_window);

	app::graphics::IRenderer* m_renderer;
	sdl::graphics::SurfaceMgr m_surfaceMgr;
	Game m_game;
};
}