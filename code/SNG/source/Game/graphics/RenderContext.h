#pragma once
#include <memory>

namespace app
{
namespace graphics
{
class IRenderer2D;
class ITextureMgr;

class RenderContext
{
public:
	RenderContext(
		std::unique_ptr<graphics::IRenderer2D> i_renderer,
		std::unique_ptr<graphics::ITextureMgr> i_textureMgr
	);
	~RenderContext();
	graphics::IRenderer2D& GetRenderer();
	const graphics::IRenderer2D& GetRenderer() const;

	graphics::ITextureMgr& GetTextureMgr();
	const graphics::ITextureMgr& GetTextureMgr() const;

private:
	std::unique_ptr<graphics::IRenderer2D> m_renderer;
	std::unique_ptr<graphics::ITextureMgr> m_textureMgr;
};

}
}