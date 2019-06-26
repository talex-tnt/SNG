#pragma once

namespace sdl
{

class Init
{
public:
	Init();
	~Init();

	Init(const Init&) = delete;
	Init(Init&&) = delete;

	Init& operator=(const Init&) = delete;
	Init& operator=(Init&&) = delete;
};

}