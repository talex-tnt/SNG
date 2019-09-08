#include "App/IApp.h"
#include "App/AppContext.h"
#include "cpp-utils/Assert.h"
#include "AppFactory.h"
#include "Game.h"

int main(int argc, char *argv[])
{
	sng::Game appDelegate;
	std::unique_ptr<app::IApp> app = sng::AppFactory::CreateApp(appDelegate);
	DB_ASSERT_MSG(app, "App creation failed.");
	if ( app )
	{
		app->Run();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
