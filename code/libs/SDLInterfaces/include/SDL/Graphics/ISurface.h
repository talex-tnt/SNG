#pragma once
#include "App/Identifiers.h"
struct SDL_Surface;

namespace sdl
{
	namespace graphics
	{
	class ISurface
	{
	public:
		virtual ~ISurface() = default;
		virtual SDL_Surface* GetSDLSurface() = 0;
		virtual const SDL_Surface* GetSDLSurface() const = 0;
		virtual bool IsValid() const = 0;
		virtual SurfaceId GetId() const = 0;
	};
	}
}