#pragma once
#include "App/Interfaces/Graphics/IRenderer.h"
#include <functional>
#include <memory>
#include "ShaderSupport.h"

namespace sdl
{
namespace ui
{
class IWindowProvider;
}
namespace graphics
{

namespace opengl
{
class TextureMgr;

class Renderer : public app::graphics::IRenderer
{
public:
	Renderer(sdl::ui::IWindowProvider& i_windowProvider);
	~Renderer();

	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;

	Renderer& operator=(const Renderer&) = delete;
	Renderer& operator=(Renderer&&) = delete;

	void RenderTexture(TextureId i_textureId, int i_posX, int i_posY) const override;
	void EndRendering() override;

	void SetTextureMgr(const TextureMgr* i_textureMgr);

private:
	bool Init(sdl::ui::IWindowProvider& i_windowProvider);

	bool m_isOpenGLInitialized;
	sdl::ui::IWindowProvider& m_windowProvider;
	typedef void SDL_GLContext;
	using GLContextUnPtr = std::unique_ptr<SDL_GLContext, std::function<void(SDL_GLContext*)>>;
	GLContextUnPtr m_glContext;
	shader_support::RenderDataContext m_renderDataContext;

	const TextureMgr* m_textureMgr;
};

}
}
}