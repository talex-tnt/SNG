#pragma once
#include <memory>
#include "App/Graphics/RenderContext.h"

namespace app
{

class AppContext
{
public:
	AppContext(
		graphics::IRenderer& i_renderer,
		graphics::ITextureMgr& i_textureMgr
	);
	~AppContext();

	graphics::RenderContext& GetRenderContext();
	const graphics::RenderContext& GetRenderContext() const;

private:
	graphics::RenderContext m_renderContext;
};

}