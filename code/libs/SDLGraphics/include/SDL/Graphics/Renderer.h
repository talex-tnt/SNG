#pragma once
#include "App/Interfaces/Graphics/IRenderer2D.h"
#include "App/Interfaces/Graphics/IRenderer.h"
#include <functional>
#include <memory>

struct SDL_Renderer;

namespace app
{
namespace graphics
{
class ITextureMgr;
}
}

namespace sdl
{
namespace ui
{
class IWindowProvider;
}
namespace graphics
{
class TextureMgr;

class Renderer 
	: public app::graphics::IRenderer
	, public app::graphics::IRenderer2D
{
public:
	Renderer(sdl::ui::IWindowProvider& i_windowProvider);
	~Renderer();

	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;

	Renderer& operator=(const Renderer&) = delete;
	Renderer& operator=(Renderer&&) = delete;

	void RenderTexture(TextureId i_textureId, int i_posX, int i_posY) const override;
	
	void BeginRendering() override;
	void EndRendering() override;

	const SDL_Renderer* GetSDLRenderer() const;
	SDL_Renderer* GetSDLRenderer();

	void SetTextureMgr(const TextureMgr* i_textureMgr);

private:
	bool Init();

	using RendererUnPtr = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer*)>>;
	RendererUnPtr m_renderer;
	const TextureMgr* m_textureMgr;
};

}
}