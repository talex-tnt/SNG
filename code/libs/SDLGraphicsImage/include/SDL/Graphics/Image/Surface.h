#pragma once
#include "App/Identifiers.h"
#include <functional>
#include "SDL/Graphics/ISurface.h"

struct SDL_Surface;

namespace sdl
{
namespace graphics
{
namespace image
{

class Surface : public sdl::graphics::ISurface
{
public:
	Surface(const TexturePath& i_path);
	~Surface() = default;

	Surface(const Surface&) = delete;
	Surface(Surface&&) = delete;

	Surface& operator=(const Surface&) = delete;
	Surface& operator=(Surface&&) = delete;

	SDL_Surface* GetSDLSurface() override;
	const SDL_Surface* GetSDLSurface() const override;

	bool IsValid() const;

private:
	using SurfacePtr = std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface*)>>;
	SurfacePtr m_surface;

};
}
}
}