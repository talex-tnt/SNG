#pragma once

namespace sdl
{
namespace ui
{
class IWindowProvider;
}

class IAppDelegate
{
public:
	virtual ~IAppDelegate() = default;
	virtual bool OnInit(ui::IWindowProvider&) = 0;
};

}