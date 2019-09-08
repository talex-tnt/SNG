#pragma once
#include <memory>
#include "App/Graphics/RenderContext.h"

namespace app
{

class AppContext
{
public:
	AppContext(
		std::unique_ptr<graphics::IRenderer> i_renderer,
		std::unique_ptr<graphics::ITextureMgr> i_textureMgr
	);
	~AppContext();

	graphics::RenderContext& GetRenderContext();
	const graphics::RenderContext& GetRenderContext() const;

private:
	graphics::RenderContext m_renderContext;
};

}