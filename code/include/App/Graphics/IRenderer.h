#pragma once
#include <memory>

namespace app
{
namespace graphics
{
class ITexture;
class ITextureMgr;

class IRenderer
{
public:
	virtual ~IRenderer() = default;
	virtual void Render(const app::graphics::ITexture& i_texture) const = 0;
};

}
}