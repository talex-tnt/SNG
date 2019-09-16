#pragma once
#include <memory>
#include "App/Identifiers.h"

namespace app
{
namespace graphics
{
class IRenderer2D
{
public:
	virtual ~IRenderer2D() = default;
	virtual void RenderTexture(TextureId i_texture, int i_posX, int i_posY) const = 0;
	virtual void EndRendering() = 0;
};

}
}