#pragma once
#include "App/Identifiers.h"
#include <functional>
#include "SDL/Graphics/ISurface.h"
#include "App/Interfaces/Graphics/IImageSurfaceLoader.h"
#include "SDL/Graphics/ISurfaceProvider.h"

struct SDL_Surface;

namespace sdl
{
namespace graphics
{
class ISurfaceMgr;
class ISurface;
namespace image
{

class SurfaceLoader : 
	public app::graphics::IImageSurfaceLoader
{
public:
	SurfaceLoader(ISurfaceMgr& i_surfaceMgr);
	~SurfaceLoader();

	SurfaceLoader(const SurfaceLoader&) = delete;
	SurfaceLoader(SurfaceLoader&&) = delete;

	SurfaceLoader& operator=(const SurfaceLoader&) = delete;
	SurfaceLoader& operator=(SurfaceLoader&&) = delete;
	
	// IImageSurfaceLoader
	SurfaceId LoadSurface(SurfacePath i_surfacePath) override;
	void UnloadSurface(SurfaceId i_surfaceId) override;

private:
	ISurfaceMgr& m_surfaceMgr;
};
}
}
}