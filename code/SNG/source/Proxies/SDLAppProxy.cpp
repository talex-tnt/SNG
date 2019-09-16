#include "SDLAppProxy.h"
#include "../Game/GameContext.h"

#include "SDL/App.h"
#include "SDL/UI/IWindowProvider.h"

#include "SDL/Graphics/Renderer.h"
#include "SDL/Graphics/TextureMgr.h"

#include "SDL/Graphics/OpenGL/Renderer.h"
#include "SDL/Graphics/OpenGL/TextureMgr.h"

#include "cpp-utils/Assert.h"

#define USE_OPENGL_RENDERER 1

namespace
{
template<class RendererT, class TextureMgrT>
std::unique_ptr<sng::GameContext> CreateAppContext(sdl::ui::IWindowProvider& i_windowProvider);
}
namespace sng
{

SDLAppProxy::~SDLAppProxy() = default;

bool SDLAppProxy::Start()
{
	//sdl::App app();
	sdl::App app(sdl::App::InitFlag::k_openGL);
	app.SetDelegate(this);
	if ( app.Init(m_game) )
	{
		app.Run();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

bool SDLAppProxy::OnInit(sdl::ui::IWindowProvider& i_windowProvider)
{
#if USE_OPENGL_RENDERER
	using RendererT = sdl::graphics::opengl::Renderer;
	using TextureMgrT = sdl::graphics::opengl::TextureMgr;
#else
	using RendererT = sdl::graphics::Renderer;
	using TextureMgrT = sdl::graphics::TextureMgr;
#endif
	return m_game.OnInit(CreateAppContext<RendererT, TextureMgrT>(i_windowProvider));
}

}

namespace
{
template<class RendererT, class TextureMgrT>
std::unique_ptr<sng::GameContext> CreateAppContext(sdl::ui::IWindowProvider& i_windowProvider)
{
	std::unique_ptr<RendererT> renderer = std::make_unique<RendererT>(i_windowProvider);
	DB_ASSERT_MSG(renderer, "Renderer Not Initialized");
	if ( renderer )
	{
		RendererT* rend = renderer.get();
		std::unique_ptr<TextureMgrT> textureMgr = std::make_unique<TextureMgrT>(*rend);
		DB_ASSERT_MSG(textureMgr, "TextureMgr Creation failed.");
		if ( textureMgr )
		{
			return std::make_unique<sng::GameContext>(std::move(renderer), std::move(textureMgr));
		}
	}
	DB_ASSERT_MSG(false, "GameContext Creation failed.");
	return nullptr;
}
}