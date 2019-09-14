#pragma once
#include <memory>
#include "Graphics/RenderContext.h"

namespace sng
{
class GameContext
{
public:
	GameContext(
		std::unique_ptr<app::graphics::IRenderer> i_renderer,
		std::unique_ptr<app::graphics::ITextureMgr> i_textureMgr
	);
	~GameContext();

	app::graphics::RenderContext& GetRenderContext();
	const app::graphics::RenderContext& GetRenderContext() const;

private:
	app::graphics::RenderContext m_renderContext;
};
}