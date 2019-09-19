#pragma once
#include "App/Identifiers.h"
#include <string>

namespace app
{
namespace graphics
{
class ITTFSurfaceLoader
{
public:
	virtual ~ITTFSurfaceLoader() = default;
	virtual SurfaceId LoadSurface(const TTFSurfaceText& i_text) = 0;
	virtual void UnloadSurface(SurfaceId i_surfaceId) = 0;
};

}
}