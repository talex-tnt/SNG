#pragma once
#include "App/Graphics/ITextureMgr.h"
#include <memory>

namespace app
{
namespace graphics
{
class ITexture;
}
}

namespace sdl
{
namespace graphics
{
class Renderer;
class Texture;

class TextureMgr : public app::graphics::ITextureMgr
{
public:
	TextureMgr(sdl::graphics::Renderer& i_renderer);
	~TextureMgr() = default;

	TextureMgr(const TextureMgr&) = delete;
	TextureMgr(TextureMgr&&) = delete;

	TextureMgr& operator=(const TextureMgr&) = delete;
	TextureMgr& operator=(TextureMgr&&) = delete;

	const app::graphics::ITexture* GetTexture() const;
	app::graphics::ITexture* GetTexture();

private:
	sdl::graphics::Renderer& m_renderer;
	bool InitImageExt();

	std::unique_ptr<sdl::graphics::Texture> m_texture;
};

}
}