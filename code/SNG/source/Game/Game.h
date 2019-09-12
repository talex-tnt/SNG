#pragma once
#include <memory>
#include "App/IAppDelegate.h"
#include "App/Identifiers.h"
#include "GameContext.h"

namespace sng
{
class GameContext;

class Game : public app::IAppDelegate
{
public:
	Game();
	~Game();
	bool OnInit(std::unique_ptr<GameContext> i_gameContext);
	bool OnInit() override;
	void OnUpdate(std::chrono::milliseconds i_deltaTime) override;
	void OnRender() override;

private:
	std::unique_ptr<GameContext> m_context;
	TextureId m_textureId;
};
}