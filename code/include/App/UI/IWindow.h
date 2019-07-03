#pragma once

namespace app
{
namespace ui
{

class IWindow
{
public:
	virtual ~IWindow() = default;
	virtual void Update() = 0;
	virtual void Render() const = 0;
};

}
}