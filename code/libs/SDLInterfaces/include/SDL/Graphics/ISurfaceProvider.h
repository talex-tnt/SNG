#pragma once
#include <memory>

namespace sdl
{
namespace graphics
{
class ISurface;

class ISurfaceProvider
{
public:
	virtual ~ISurfaceProvider() = default;
	virtual std::unique_ptr<ISurface> Create() = 0;
};

}
}