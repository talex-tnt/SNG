#include "SDL/Graphics/Image/SurfaceLoader.h"
#include "cpp-utils/Assert.h"
#include "SDL/Graphics/ISurfaceMgr.h"
#include "SDL/Graphics/ISurface.h"
#include "Surface.h"

namespace
{
struct Provider : public sdl::graphics::ISurfaceProvider
{
	Provider(SurfacePath i_path) : m_path(i_path) { }
	~Provider() = default;
	SurfacePath m_path;
	std::unique_ptr<sdl::graphics::ISurface> Create() override
	{
		return std::make_unique<sdl::graphics::image::Surface>(m_path);
	}
};
}

namespace sdl
{
namespace graphics
{
namespace image
{

SurfaceLoader::SurfaceLoader(ISurfaceMgr& i_surfaceMgr) 
	: m_surfaceMgr(i_surfaceMgr) { }

SurfaceLoader::~SurfaceLoader() = default;

SurfaceId SurfaceLoader::LoadSurface(SurfacePath i_surfacePath)
{
	return m_surfaceMgr.LoadSurface(Provider(i_surfacePath));
}

void SurfaceLoader::UnloadSurface(SurfaceId i_surfaceId)
{
	m_surfaceMgr.UnloadSurface(i_surfaceId);
}

}
}
}