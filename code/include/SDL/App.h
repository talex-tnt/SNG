#pragma once

namespace sdl
{

class App
{
public:
	App();
	~App();

	App(const App&) = delete;
	App(App&&) = delete;

	App& operator=(const App&) = delete;
	App& operator=(App&&) = delete;

	bool Init();
private:
	bool m_initialized;
};

}