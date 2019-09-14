#pragma once
#include <memory>
#include "App/Identifiers.h"

namespace app
{
namespace graphics
{
class IRenderer
{
public:
	virtual ~IRenderer() = default;
	virtual void RenderTexture(TextureId i_texture, int i_posX, int i_posY) const = 0;
};

}
}