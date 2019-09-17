#include "SDL/Graphics/Image/Surface.h"

#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#	include <SDL.h>
#	include <SDL_image.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include "cpp-utils/Assert.h"

namespace sdl
{
namespace graphics
{
namespace image
{

Surface::Surface(const TexturePath& i_path)
: m_surface(
	IMG_Load(i_path.GetValue().c_str()),
	[] (SDL_Surface* s) { SDL_FreeSurface(s); })
{
	DB_ASSERT_MSG(m_surface, "Unable to create sdl::graphics::image::Surface with path " << i_path << ": " << SDL_GetError());
}

SDL_Surface* Surface::GetSDLSurface()
{
	return m_surface ? m_surface.get() : nullptr;
}

const SDL_Surface* Surface::GetSDLSurface() const
{
	return m_surface ? m_surface.get() : nullptr;
}

bool Surface::IsValid() const
{
	return m_surface != nullptr;
}

}
}
}