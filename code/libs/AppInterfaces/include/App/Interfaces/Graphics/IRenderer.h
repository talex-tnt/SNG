#pragma once
#include <memory>

namespace app
{
namespace graphics
{
class IRenderer
{
public:
	virtual ~IRenderer() = default;
	virtual void BeginRendering() = 0;
	virtual void EndRendering() = 0;
};

}
}