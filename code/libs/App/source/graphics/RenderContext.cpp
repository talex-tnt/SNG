#include "App/Graphics/RenderContext.h"
#include "App/Graphics/IRenderer.h"
#include "App/Graphics/ITextureMgr.h"

namespace app
{
namespace graphics
{
RenderContext::RenderContext(
	std::unique_ptr<graphics::IRenderer> i_renderer, 
	std::unique_ptr< graphics::ITextureMgr> i_textureMgr)
	: m_renderer(std::move(i_renderer))
	, m_textureMgr(std::move(i_textureMgr))
{

}

RenderContext::~RenderContext() = default;

app::graphics::IRenderer& RenderContext::GetRenderer()
{
	return *m_renderer;
}

const app::graphics::IRenderer& RenderContext::GetRenderer() const
{
	return *m_renderer;
}

app::graphics::ITextureMgr& RenderContext::GetTextureMgr()
{
	return *m_textureMgr;
}

const app::graphics::ITextureMgr& RenderContext::GetTextureMgr() const
{
	return *m_textureMgr;
}

}
}
