#pragma once
#include <memory>

namespace app
{
namespace graphics
{
class IRenderer;
class ITextureMgr;

class RenderContext
{
public:
	RenderContext(
		graphics::IRenderer& i_renderer,
		graphics::ITextureMgr& i_textureMgr
	);
	~RenderContext();
	graphics::IRenderer& GetRenderer();
	const graphics::IRenderer& GetRenderer() const;

	graphics::ITextureMgr& GetTextureMgr();
	const graphics::ITextureMgr& GetTextureMgr() const;

private:
	graphics::IRenderer& m_renderer;
	graphics::ITextureMgr& m_textureMgr;
};

}
}