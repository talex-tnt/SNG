#include "App/Graphics/RenderContext.h"

namespace app
{
namespace graphics
{
RenderContext::RenderContext(graphics::IRenderer& i_renderer, graphics::ITextureMgr& i_textureMgr)
	: m_renderer(i_renderer)
	, m_textureMgr(i_textureMgr)
{

}

RenderContext::~RenderContext() = default;

app::graphics::IRenderer& RenderContext::GetRenderer()
{
	return m_renderer;
}

const app::graphics::IRenderer& RenderContext::GetRenderer() const
{
	return m_renderer;
}

app::graphics::ITextureMgr& RenderContext::GetTextureMgr()
{
	return m_textureMgr;
}

const app::graphics::ITextureMgr& RenderContext::GetTextureMgr() const
{
	return m_textureMgr;
}

}
}
