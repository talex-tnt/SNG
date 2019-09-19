#include "SDL/Graphics/SurfaceMgr.h"
#include "SDL/Graphics/ISurfaceProvider.h"
#include "SDL/Graphics/ISurface.h"
#include "cpp-utils/Assert.h"
#include <algorithm>

namespace sdl
{
namespace graphics
{

SurfaceMgr::~SurfaceMgr() = default;

SurfaceMgr::SurfaceMgr() = default;

SurfaceId SurfaceMgr::LoadSurface(ISurfaceProvider& i_surfaceProvider)
{
	SurfaceId surfaceId;
	std::unique_ptr<ISurface> surface = i_surfaceProvider.Create();
	DB_ASSERT_MSG(surface->IsValid(), "Couldn't create the surface");
	if ( surface->IsValid() )
	{
		surfaceId = surface->GetId();
		const ISurface* prevSur = FindSurfaceById(surfaceId);
		DB_ASSERT_MSG(prevSur == nullptr, "Surface with id " << surfaceId << " was already created.");
		if ( prevSur == nullptr )
		{
			m_surfaces.emplace(surfaceId, std::move(surface));
		}
	}
	return surfaceId;
}

void SurfaceMgr::UnloadSurface(SurfaceId i_surfaceId)
{
	auto it = m_surfaces.find(i_surfaceId);
	if ( it != m_surfaces.end() )
	{
		m_surfaces.erase(it);
	}
}

const ISurface* SurfaceMgr::FindSurfaceById(SurfaceId i_surfaceId) const
{
	auto it = m_surfaces.find(i_surfaceId);
	if ( it != m_surfaces.end() )
	{
		return it->second.get();
	}
	return nullptr;
}

ISurface* SurfaceMgr::FindSurfaceById(SurfaceId i_surfaceId)
{
	const SurfaceMgr& const_this = static_cast< const SurfaceMgr& >( *this );
	const ISurface* const_text = const_this.FindSurfaceById(i_surfaceId);
	return const_cast< ISurface * >( const_text );
}

} // namespace graphics
} // namespace sdl
