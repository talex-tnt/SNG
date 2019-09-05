#pragma once
#include <memory>

namespace app
{
class AppContext;

namespace graphics
{
class RenderContext;
}
class IAppDelegate
{
public:
	virtual ~IAppDelegate() = default;
	virtual bool OnInit(app::AppContext& i_appContext) = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender(app::graphics::RenderContext& i_context) = 0;
};

}