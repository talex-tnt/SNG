#pragma once

namespace app
{
namespace graphics
{

class ITexture
{
public:
	virtual ~ITexture() = default;
	//#TODO.. is this really required??
	virtual void Render(int x, int y) const = 0;
	virtual bool IsValid() const = 0;
};

}
}