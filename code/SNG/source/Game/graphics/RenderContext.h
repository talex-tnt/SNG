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
		std::unique_ptr<graphics::IRenderer> i_renderer,
		std::unique_ptr<graphics::ITextureMgr> i_textureMgr
	);
	~RenderContext();
	graphics::IRenderer& GetRenderer();
	const graphics::IRenderer& GetRenderer() const;

	graphics::ITextureMgr& GetTextureMgr();
	const graphics::ITextureMgr& GetTextureMgr() const;

private:
	std::unique_ptr<graphics::IRenderer> m_renderer;
	std::unique_ptr<graphics::ITextureMgr> m_textureMgr;
};

}
}