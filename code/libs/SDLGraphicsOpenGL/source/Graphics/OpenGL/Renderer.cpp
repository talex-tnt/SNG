#include "SDL/Graphics/OpenGL/Renderer.h"

#include "SDL/UI/IWindowProvider.h"
#include "SDL/Graphics/OpenGL/ShaderSupport.h"

#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#	include <SDL_render.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include "cpp-utils/Assert.h"
#include "cpp-utils/Placeholder.h"
#include "cpp-utils/Log.h"

namespace sdl
{
namespace graphics
{
namespace opengl
{

Renderer::Renderer(sdl::ui::IWindowProvider& i_windowProvider)
	: m_windowProvider(i_windowProvider)
	, m_glContext(
		SDL_GL_CreateContext(i_windowProvider.GetSDLWindow()),
		[] (SDL_GLContext* context) { SDL_GL_DeleteContext(context); })
{
	DB_ASSERT_MSG(m_glContext, "Could Not Create the SDL_GLContext: " << SDL_GetError());
	Init();
}

Renderer::~Renderer() = default;

void Renderer::RenderTexture(TextureId i_textureId, int i_posX, int i_posY) const
{
	shader_support::Render(m_renderDataContext);
}

void Renderer::EndRendering()
{
	SDL_GL_SwapWindow(m_windowProvider.GetSDLWindow());
}

bool Renderer::Init()
{
	m_isOpenGLInitialized = shader_support::InitGLExtensions();
	DB_ASSERT_MSG(m_isOpenGLInitialized, "Couldn't init GL extensions!");
	if ( m_isOpenGLInitialized )
	{
		DB_LOG("GL extensions initialized");
		const std::string vxtShaderName = utils::Placeholder("std.vertex");
		const std::string frgShaderName = utils::Placeholder("std.fragment");
		auto shaderProgram = shader_support::PrepareShaderProgram(vxtShaderName, frgShaderName);
		if ( shaderProgram.first )
		{
			m_renderDataContext = shader_support::PrepareRenderContext(shaderProgram.second);
			m_renderDataContext.resolution[ 0 ] = static_cast< float >( utils::Placeholder(640) );
			m_renderDataContext.resolution[ 1 ] = static_cast< float >( utils::Placeholder(480) );
		}
		DB_LOG("programId = " << shaderProgram.first);
	}
	return m_isOpenGLInitialized;
}



} // namespace graphics
} // namespace opengl
} // namespace sdl
