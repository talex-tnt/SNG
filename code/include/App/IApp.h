#pragma once

namespace app
{

class IApp
{
public:
	virtual ~IApp() = default;
	virtual bool Init() = 0;
	virtual void Run() = 0;
};

}