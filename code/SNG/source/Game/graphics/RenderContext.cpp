#include "RenderContext.h"
#include "App/Interfaces/Graphics/IRenderer2D.h"
#include "App/Interfaces/Graphics/ITextureMgr.h"

namespace app
{
namespace graphics
{
RenderContext::RenderContext(
	std::unique_ptr<graphics::IRenderer2D> i_renderer, 
	std::unique_ptr< graphics::ITextureMgr> i_textureMgr)
	: m_renderer(std::move(i_renderer))
	, m_textureMgr(std::move(i_textureMgr))
{

}

RenderContext::~RenderContext() = default;

app::graphics::IRenderer2D& RenderContext::GetRenderer()
{
	return *m_renderer;
}

const app::graphics::IRenderer2D& RenderContext::GetRenderer() const
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
