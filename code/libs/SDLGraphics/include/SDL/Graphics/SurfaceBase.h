#pragma once
#include "App/Identifiers.h"
#include "SDL/Graphics/ISurface.h"
#include <functional>

struct SDL_Surface;

namespace sdl
{
namespace graphics
{

class SurfaceBase : public ISurface
{
public:
	SurfaceBase() = delete;
	virtual ~SurfaceBase(); 

	SurfaceBase(const SurfaceBase&) = delete;
	SurfaceBase(SurfaceBase&&) = delete;

	SurfaceBase& operator=(const SurfaceBase&) = delete;
	SurfaceBase& operator=(SurfaceBase&&) = delete;

	SDL_Surface* GetSDLSurface();
	const SDL_Surface* GetSDLSurface() const;

	bool IsValid() const override;

private:
	using SurfacePtr = std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface*)>>;
	SurfacePtr m_surface;
};
}
}