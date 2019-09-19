#pragma once
#include "App/Identifiers.h"

namespace sdl
{
namespace graphics
{
class ISurfaceProvider;
class ISurfaceMgr
{
public:
	virtual ~ISurfaceMgr() = default;
	virtual SurfaceId LoadSurface(ISurfaceProvider& i_surface) = 0;
	virtual void UnloadSurface(SurfaceId i_surfaceId) = 0;

};

}
}