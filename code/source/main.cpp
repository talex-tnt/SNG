#include "AppFactory.h"
#include "App/IApp.h"
#include "cpp-utils/Assert.h"

int main(int argc, char *argv[])
{
	sng::AppFactory appFactory;
	std::unique_ptr<app::IApp> app = appFactory.CreateApp();
	DB_ASSERT_MSG(app, "App creation failed.");
	if ( app &&  app->Init() )
	{
		app->Run();
	}
  return 0;
}