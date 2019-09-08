#pragma once
#include <memory>

namespace app
{
class IApp;
class IAppDelegate;
}

namespace sng
{
class AppFactory
{
public:
static std::unique_ptr<app::IApp> CreateApp(app::IAppDelegate& i_appDelegate);

};
}