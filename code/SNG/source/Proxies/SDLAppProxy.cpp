#include "SDLAppProxy.h"
#include "../Game/GameContext.h"

#include "SDL/App.h"
#include "SDL/UI/IWindow.h"

#include "SDL/Graphics/Renderer.h"
#include "SDL/Graphics/TextureMgr.h"

#include "SDL/Graphics/OpenGL/Renderer.h"
#include "SDL/Graphics/OpenGL/TextureMgr.h"

#include "cpp-utils/Assert.h"

#define USE_OPENGL_RENDERER 1

namespace
{

}
namespace sng
{

SDLAppProxy::SDLAppProxy() 
	: m_renderer(nullptr)
{

}

SDLAppProxy::~SDLAppProxy() = default;

bool SDLAppProxy::Start()
{
	//sdl::App app();
	sdl::App app(sdl::App::InitFlag::k_openGL);
	app.SetDelegate(this);
	if ( app.Init(m_game) && m_renderer)
	{
		app.Run(*m_renderer);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

bool SDLAppProxy::OnInit(sdl::ui::IWindow& i_window)
{
#if USE_OPENGL_RENDERER
	using RendererT = sdl::graphics::opengl::Renderer;
	using TextureMgrT = sdl::graphics::opengl::TextureMgr;
#else
	using RendererT = sdl::graphics::Renderer;
	using TextureMgrT = sdl::graphics::TextureMgr;
#endif
	return m_game.OnInit(CreateGameContext<RendererT, TextureMgrT>(i_window));
}

template<class RendererT, class TextureMgrT>
std::unique_ptr<sng::GameContext> SDLAppProxy::CreateGameContext(sdl::ui::IWindow& i_window)
{
	std::unique_ptr<RendererT> renderer = std::make_unique<RendererT>(i_window);
	DB_ASSERT_MSG(renderer, "Renderer Not Initialized");
	if ( renderer )
	{
		m_renderer = renderer.get();
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