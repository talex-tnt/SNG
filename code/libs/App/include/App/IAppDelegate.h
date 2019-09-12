#pragma once
#include <chrono>

namespace app
{
class IAppDelegate
{
public:
	virtual ~IAppDelegate() = default;
	virtual bool OnInit() = 0;
	virtual void OnUpdate(std::chrono::milliseconds i_deltaTime) = 0;
	virtual void OnRender() = 0;
};

}