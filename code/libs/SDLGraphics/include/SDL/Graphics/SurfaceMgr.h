#pragma once
#include "App/Identifiers.h"
#include <unordered_map>
#include "SDL/Graphics/ISurfaceMgr.h"

namespace sdl
{
namespace graphics
{
class ISurface;
class ISurfaceProvider;

class SurfaceMgr : public ISurfaceMgr
{
public:
	SurfaceMgr();
	~SurfaceMgr();

	SurfaceMgr(const SurfaceMgr&) = delete;
	SurfaceMgr(SurfaceMgr&&) = delete;

	SurfaceMgr& operator=(const SurfaceMgr&) = delete;
	SurfaceMgr& operator=(SurfaceMgr&&) = delete;

	SurfaceId LoadSurface(ISurfaceProvider& i_surface) override;
	void UnloadSurface(SurfaceId i_surfaceId) override;

	const ISurface* FindSurfaceById(SurfaceId i_surfaceId) const;
	ISurface* FindSurfaceById(SurfaceId i_surfaceId);

private:
	using SurfacePtr = std::unique_ptr<ISurface>;
	using SurfaceMap = std::unordered_map<SurfaceId, SurfacePtr, SurfaceId::Hasher>;
	SurfaceMap m_surfaces;
};

}
}