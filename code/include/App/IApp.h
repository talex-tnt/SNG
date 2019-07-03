#pragma once
#include <memory>

namespace app
{
class IUIFactory;
class IApp
{
public:
	virtual ~IApp() = default;
	virtual bool Init() = 0;
	virtual void Run() = 0;

protected:
	virtual std::unique_ptr<IUIFactory> CreateUIFactory() = 0;
};

}