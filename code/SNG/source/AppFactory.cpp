#include "AppFactory.h"
#include "App/AppContext.h"
#include "SDL/App.h"
#include "SDL/Graphics/Renderer.h"
#include "SDL/Graphics/TextureMgr.h"
#include "cpp-utils/Assert.h"
#include "App/IApp.h"

namespace 
{ 
class AppContextFactory : public sdl::IAppContextFactory
{
public:
std::unique_ptr<app::AppContext> CreateAppContext(sdl::ui::IWindowProvider& i_windowProvider) override;
};
}

namespace sng
{

std::unique_ptr<app::IApp> AppFactory::CreateApp(app::IAppDelegate& i_appDelegate)
{
	std::unique_ptr<sdl::App> app = std::make_unique<sdl::App>(std::make_unique<AppContextFactory>());
	if ( app &&  app->Init(i_appDelegate))
	{
		return app;
	}
	return nullptr;
}

}

namespace
{
std::unique_ptr<app::AppContext> AppContextFactory::CreateAppContext(sdl::ui::IWindowProvider& i_windowProvider)
{
	std::unique_ptr<sdl::graphics::Renderer> renderer =
		std::make_unique<sdl::graphics::Renderer>(i_windowProvider);
	DB_ASSERT_MSG(renderer, "Renderer Not Initialized");
	if ( renderer )
	{
		sdl::graphics::Renderer* rend = renderer.get();
		std::unique_ptr<sdl::graphics::TextureMgr> textureMgr =
			std::make_unique<sdl::graphics::TextureMgr>(*rend);
		DB_ASSERT_MSG(textureMgr, "TextureMgr Creation failed.");
		if ( textureMgr )
		{
			return std::make_unique<app::AppContext>(std::move(renderer), std::move(textureMgr));
		}
	}
	DB_ASSERT_MSG(false, "AppContext Creation failed.");
	return nullptr;
}

}
