#include "App/AppContext.h"

namespace app
{ 

AppContext::AppContext(graphics::IRenderer& i_renderer, graphics::ITextureMgr& i_textureMgr)
	: m_renderContext(i_renderer, i_textureMgr)
{

}

AppContext::~AppContext() = default;

app::graphics::RenderContext& AppContext::GetRenderContext()
{
	return m_renderContext;
}

const app::graphics::RenderContext& AppContext::GetRenderContext() const
{
	return m_renderContext;
}

}
