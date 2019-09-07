#pragma once
#include "App/Identifiers.h"

namespace app
{
namespace graphics
{
class ITexture;
class ITextureMgr
{
public:
	virtual ~ITextureMgr() = default;
	virtual TextureId CreateTexture(TexturePath i_path) = 0;
};

}
}