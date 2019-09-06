#pragma once
#include <memory>
#include "App/IAppDelegate.h"
#include "App/Identifiers.h"

namespace app
{
class AppContext;
}

namespace sng
{
class Game : public app::IAppDelegate
{
public:
	bool OnInit(app::AppContext& i_appContext) override;
	void OnUpdate(std::chrono::milliseconds) override;
	void OnRender(app::graphics::RenderContext& i_context) override;

private:
	TextureId m_textureId;
};
}