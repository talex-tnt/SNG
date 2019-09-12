#include "GameContext.h"
#include "App/Graphics/IRenderer.h"
#include "App/Graphics/ITextureMgr.h"

namespace sng
{ 

GameContext::GameContext(
	std::unique_ptr < app::graphics::IRenderer> i_renderer, 
	std::unique_ptr < app::graphics::ITextureMgr> i_textureMgr
)
	: m_renderContext(std::move(i_renderer), std::move(i_textureMgr))
{

}

GameContext::~GameContext() = default;

app::graphics::RenderContext& GameContext::GetRenderContext()
{
	return m_renderContext;
}

const app::graphics::RenderContext& GameContext::GetRenderContext() const
{
	return m_renderContext;
}

}
