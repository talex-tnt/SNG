#pragma once
#include <utility>
#include <cstdint>
#include <string>
#include <array>

typedef unsigned int GLuint;
typedef int GLint;

namespace shader_support
{


struct RenderBuffers
{
	GLuint VBO = 0;
	GLuint IBO = 0;
};
struct RenderDataContext
{
	GLuint shaderProgramId = 0;
	GLint vertexPosAttrLoc = 0;
	std::array<float, 2> resolution = { 0, 0 };
	RenderBuffers buffers;
};

bool InitGLExtensions();
std::pair<bool, GLuint> PrepareShaderProgram(const std::string& i_vertexShaderPath, const std::string& i_fragmentShaderPath);
RenderDataContext PrepareRenderContext(GLuint i_shaderProgramId);
void DeleteShaderProgram(GLuint i_shaderProgramId);
void Render(const RenderDataContext& i_ctx);

void RunTest();
}