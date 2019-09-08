#include "App/AppContext.h"
#include "App/Graphics/IRenderer.h"
#include "App/Graphics/ITextureMgr.h"
namespace app
{ 

AppContext::AppContext(
	std::unique_ptr < graphics::IRenderer> i_renderer, 
	std::unique_ptr < graphics::ITextureMgr> i_textureMgr
)
	: m_renderContext(std::move(i_renderer), std::move(i_textureMgr))
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
