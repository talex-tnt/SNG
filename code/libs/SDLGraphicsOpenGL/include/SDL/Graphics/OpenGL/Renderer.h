#pragma once
#include "App/Interfaces/Graphics/IRenderer.h"
#include "App/Interfaces/Graphics/IRenderer2D.h"
#include <functional>
#include <memory>
#include "ShaderSupport.h"

namespace sdl
{
namespace ui
{
class IWindow;
}
namespace graphics
{

namespace opengl
{
class TextureMgr;

class Renderer 
	: public app::graphics::IRenderer
	, public app::graphics::IRenderer2D
{
public:
	Renderer(sdl::ui::IWindow& i_window);
	~Renderer();

	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) = delete;

	Renderer& operator=(const Renderer&) = delete;
	Renderer& operator=(Renderer&&) = delete;

	void RenderTexture(TextureId i_textureId, int i_posX, int i_posY) const override;
	
	void BeginRendering() override;
	void EndRendering() override;

	void SetTextureMgr(const TextureMgr* i_textureMgr);

private:
	bool Init(sdl::ui::IWindow& i_window);

	bool m_isOpenGLInitialized;
	sdl::ui::IWindow& m_windowProvider;
	typedef void SDL_GLContext;
	using GLContextUnPtr = std::unique_ptr<SDL_GLContext, std::function<void(SDL_GLContext*)>>;
	GLContextUnPtr m_glContext;
	shader_support::RenderDataContext m_renderDataContext;

	const TextureMgr* m_textureMgr;
};

}
}
}