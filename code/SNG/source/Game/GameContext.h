#pragma once
#include <memory>
#include "Graphics/RenderContext.h"

namespace app
{
namespace graphics
{
class IImageSurfaceLoader;
}
}
namespace sng
{
class GameContext
{
public:
	using SurfaceImageLoader = app::graphics::IImageSurfaceLoader;
	using SurfaceImageLoaderPtr = std::unique_ptr<SurfaceImageLoader>;
	GameContext(
		std::unique_ptr<app::graphics::IRenderer2D> i_renderer,
		std::unique_ptr<app::graphics::ITextureMgr> i_textureMgr,
		SurfaceImageLoaderPtr i_imageLoader
	);
	~GameContext();

	app::graphics::RenderContext& GetRenderContext();
	const app::graphics::RenderContext& GetRenderContext() const;

	SurfaceImageLoader& GetSurfaceImageLoader();
	const SurfaceImageLoader& GetSurfaceImageLoader() const;
private:
	app::graphics::RenderContext m_renderContext;
	SurfaceImageLoaderPtr m_imageLoader;
};
}