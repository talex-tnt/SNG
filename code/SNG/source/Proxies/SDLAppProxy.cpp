#include "SDLAppProxy.h"
#include "../Game/GameContext.h"
#include "SDL/UI/IWindowProvider.h"
#include "SDL/Graphics/Renderer.h"
#include "SDL/Graphics/TextureMgr.h"
#include "cpp-utils/Assert.h"
#include "SDL/App.h"
#include "SDL/Graphics/OpenGL/Renderer.h"


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
	return m_game.OnInit(CreateAppContext(i_windowProvider));
}

std::unique_ptr<sng::GameContext> SDLAppProxy::CreateAppContext(sdl::ui::IWindowProvider& i_windowProvider)
{
	//using RendererT = sdl::graphics::Renderer;
	using RendererT = sdl::graphics::opengl::Renderer;
	std::unique_ptr<RendererT> renderer =
		std::make_unique<RendererT>(i_windowProvider);
	DB_ASSERT_MSG(renderer, "Renderer Not Initialized");
	if ( renderer )
	{
		return std::make_unique<sng::GameContext>(std::move(renderer), nullptr);
		//RendererT* rend = renderer.get();
		//std::unique_ptr<sdl::graphics::TextureMgr> textureMgr =
		//	std::make_unique<sdl::graphics::TextureMgr>(*rend);
		//DB_ASSERT_MSG(textureMgr, "TextureMgr Creation failed.");
		//if ( textureMgr )
		//{
		//	return std::make_unique<sng::GameContext>(std::move(renderer), std::move(textureMgr));
		//}
	}
	DB_ASSERT_MSG(false, "GameContext Creation failed.");
	return nullptr;
}

}
