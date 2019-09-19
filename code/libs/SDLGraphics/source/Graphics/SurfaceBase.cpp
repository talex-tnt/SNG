#include "SDL/Graphics/SurfaceBase.h"
#include "cpp-utils/Assert.h"

namespace sdl
{
namespace graphics
{

SurfaceBase::~SurfaceBase() = default;

SDL_Surface* SurfaceBase::GetSDLSurface()
{
	return m_surface ? m_surface.get() : nullptr;
}

const SDL_Surface* SurfaceBase::GetSDLSurface() const
{
	return m_surface ? m_surface.get() : nullptr;
}

bool SurfaceBase::IsValid() const
{
	return m_surface != nullptr;
}

}
}