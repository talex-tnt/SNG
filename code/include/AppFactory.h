#pragma once
#include <memory>
#include "App/IUIFactory.h"

namespace app
{
class IApp;
}

namespace sng
{
class AppFactory
{
public:
static std::unique_ptr<app::IApp> CreateApp();
};
}