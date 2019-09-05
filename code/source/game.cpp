#include "Game.h"

#include "App/Graphics/ITexture.h"
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

void Game::OnUpdate()
{

}

void Game::OnRender(app::graphics::RenderContext& i_context)
{
	if ( const app::graphics::ITexture* texture = i_context.GetTextureMgr().FindTextureById(m_textureId) )
	{
		i_context.GetRenderer().Render(*texture);
	}
}

}