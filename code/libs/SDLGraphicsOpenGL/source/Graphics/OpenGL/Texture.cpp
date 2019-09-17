#include "Texture.h"
#include "cpp-utils/Assert.h"

#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#	include <SDL.h>
#	include <SDL_image.h>
#	include <SDL_opengl.h>
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include "cpp-utils/Log.h"

namespace sdl
{
namespace graphics
{
namespace opengl
{

Texture::Texture(const TexturePath& i_path) 
	: m_textureId(0u)
	, m_width(0u)
	, m_height(0u)
{
	SDL_Surface* surface = IMG_Load(i_path.GetValue().c_str());
	DB_ASSERT_MSG(surface, "Could Not Create the SDL_Surface: " << SDL_GetError());
	if ( surface )
	{
		m_width = surface->w;
		m_height = surface->h;

		glGenTextures(1, &m_textureId);
		glBindTexture(GL_TEXTURE_2D, m_textureId);

		GLenum mode = 0u;
		const int nOfColors = surface->format->BytesPerPixel;
		DB_ASSERT_MSG(nOfColors == 3 || nOfColors == 4, "Unexpected number of colors for image: " << i_path);
		if ( nOfColors == 4 )     // contains an alpha channel
		{
			mode = surface->format->Rmask == 0x000000ff ? GL_RGBA : GL_BGRA;
		}
		else if ( nOfColors == 3 )     // no alpha channel
		{
			mode = surface->format->Rmask == 0x000000ff ? GL_RGB : GL_BGR;
		}

		DB_LOG("BytesPerPixel:" + std::to_string(surface->format->BytesPerPixel));
		glTexImage2D(GL_TEXTURE_2D,
					 0u, 
					 mode, 
					 static_cast<GLsizei>(m_width), 
					 static_cast< GLsizei >( m_height), 
					 0u, 
					 mode, 
					 GL_UNSIGNED_BYTE, 
					 surface->pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		SDL_FreeSurface(surface);
	}
}

Texture::~Texture()
{
	if( IsValid() )
	{
		glDeleteTextures(1, &m_textureId);
	}
}

void Texture::Render(int i_x, int i_y) const
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, m_textureId);
	{
		const float x = static_cast<float>(i_x);
		const float y = static_cast<float>(i_y);
		const std::size_t width = m_width;
		const std::size_t height = m_height;
		//DB_LOG("w:" + std::to_string(width) + " h:" + std::to_string(height));
		glBegin(GL_QUADS);
		glTexCoord2f(0.f, 0.f); glVertex3f(x, y, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(x + width, y, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(x + width, y + height, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(x, y + height, 0.f);
		glEnd();
	}
}

bool Texture::IsValid() const
{
	return m_textureId != 0u;
}

} // namespace opengl
} // namespace graphics
} // namespace sdl
