#pragma once
#include <string>
#include <functional>
#include "App/Identifiers.h"

namespace sdl
{
namespace graphics
{
namespace opengl
{
typedef unsigned int GLuint;
typedef int GLint;

class Texture
{
public:
	Texture(const TexturePath& i_path);
	~Texture();

	Texture(const Texture&) = delete;
	Texture(Texture&&) = delete;

	Texture& operator=(const Texture&) = delete;
	Texture& operator=(Texture&&) = delete;


	void Render(int x, int y) const;
	bool IsValid() const;

private:
	GLuint m_textureId;
	std::size_t m_width;
	std::size_t m_height;
};
}
}
}