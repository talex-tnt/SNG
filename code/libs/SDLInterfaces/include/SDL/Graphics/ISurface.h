#pragma once
struct SDL_Surface;

namespace sdl
{
	namespace graphics
	{
	class ISurface
	{
	public:
		virtual SDL_Surface* GetSDLSurface() = 0;
		virtual const SDL_Surface* GetSDLSurface() const = 0;

	protected:
		~ISurface() = default;
	};
	}
}