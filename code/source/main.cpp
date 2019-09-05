#include "App/IApp.h"
#include "cpp-utils/Assert.h"
#include "AppFactory.h"
#include "Game.h"

int main(int argc, char *argv[])
{
	std::unique_ptr<app::IApp> app = sng::AppFactory::CreateApp();
	DB_ASSERT_MSG(app, "App creation failed.");
	sng::Game game;
	if ( app &&  app->Init(game) )
	{
		app->Run();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
