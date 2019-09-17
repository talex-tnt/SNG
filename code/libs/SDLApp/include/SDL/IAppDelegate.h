#pragma once

namespace sdl
{
namespace ui
{
class IWindow;
}

class IAppDelegate
{
public:
	virtual ~IAppDelegate() = default;
	virtual bool OnInit(ui::IWindow&) = 0;
};

}