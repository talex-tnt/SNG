#include "Game.h"

#include "App/Graphics/RenderContext.h"
#include "App/Graphics/ITextureMgr.h"
#include "App/Graphics/IRenderer.h"
#include "App/AppContext.h"

namespace sng
{
bool Game::OnInit(app::AppContext& i_appContext)
{
	app::graphics::ITextureMgr& textureMgr = i_appContext.GetRenderContext().GetTextureMgr();
	m_textureId = textureMgr.CreateTexture(TexturePath("images/SDL_Logo.png"));
	return true;
}

void Game::OnUpdate(std::chrono::milliseconds i_deltaTime)
{

}

void Game::OnRender(app::graphics::RenderContext& i_context)
{
	i_context.GetRenderer().RenderTexture(m_textureId, 0u, 0u);
}

}