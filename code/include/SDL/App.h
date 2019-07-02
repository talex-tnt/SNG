#pragma once
#include "App/IApp.h"

namespace sdl
{

class App : public app::IApp
{
public:
	App();
	~App();

	App(const App&) = delete;
	App(App&&) = delete;

	App& operator=(const App&) = delete;
	App& operator=(App&&) = delete;

	bool Init() override;
	void Run() override;

private:
	bool m_initialized;
};

}