#include "GameContext.h"
#include "App/Interfaces/Graphics/IRenderer2D.h"
#include "App/Interfaces/Graphics/ITextureMgr.h"
#include "App/Interfaces/Graphics/IImageSurfaceLoader.h"

namespace sng
{ 

GameContext::GameContext(
	std::unique_ptr < app::graphics::IRenderer2D> i_renderer, 
	std::unique_ptr < app::graphics::ITextureMgr> i_textureMgr,
	SurfaceImageLoaderPtr i_imageLoader
)
	: m_renderContext(std::move(i_renderer), std::move(i_textureMgr))
	, m_imageLoader(std::move(i_imageLoader))
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

const sng::GameContext::SurfaceImageLoader& GameContext::GetSurfaceImageLoader() const
{
	return *m_imageLoader;
}

sng::GameContext::SurfaceImageLoader& GameContext::GetSurfaceImageLoader()
{
	return *m_imageLoader;
}

}
