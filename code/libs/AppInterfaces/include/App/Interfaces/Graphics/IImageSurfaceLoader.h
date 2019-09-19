#pragma once
#include "App/Identifiers.h"

namespace app
{
namespace graphics
{
class IImageSurfaceLoader
{
public:
	virtual ~IImageSurfaceLoader() = default;
	virtual SurfaceId LoadSurface(SurfacePath i_surfacePath) = 0;
	virtual void UnloadSurface(SurfaceId i_surfaceId) = 0;
};

}
}