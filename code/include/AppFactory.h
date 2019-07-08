#pragma once
#include <memory>

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