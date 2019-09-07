#include "Renderer.h"
#include "TextureMgr.h"
#include "Texture.h"

#include "../UI/Window.h"
#include "SDL_render.h"

#include "cpp-utils/Assert.h"




namespace sdl
{
namespace graphics
{
const uint32_t k_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
const int k_index = -1;

Renderer::Renderer(ui::Window& i_window)
	: m_renderer(
		SDL_CreateRenderer(i_window.GetSDLWindow(), k_index, k_flags),
		[] (SDL_Renderer* renderer) { SDL_DestroyRenderer(renderer); })
{
	DB_ASSERT_MSG(m_renderer, "Could Not Create the SDL_Renderer");
	Init();
}

Renderer::~Renderer() = default;

void Renderer::RenderTexture(TextureId i_textureId, int i_posX, int i_posY) const
{
	SDL_RenderClear(m_renderer.get());
	const sdl::graphics::Texture* texture = m_textureMgr 
		? m_textureMgr->_FindTextureById(i_textureId) 
		: nullptr;
	if ( texture )
	{
		texture->Render(i_posX, i_posY);
	}
	SDL_RenderPresent(m_renderer.get());
}

bool Renderer::Init()
{
	DB_ASSERT_MSG(m_renderer, "Could Not Create the SDL_Renderer");
	SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_renderer.get());
	SDL_RenderPresent(m_renderer.get());

	return m_renderer != nullptr;
}

SDL_Renderer* Renderer::GetSDLRenderer()
{
	DB_ASSERT_MSG(m_renderer, "Could Not Create the SDL_Renderer");
	return m_renderer ? m_renderer.get() : nullptr;
}

const SDL_Renderer* Renderer::GetSDLRenderer() const
{
	DB_ASSERT_MSG(m_renderer, "Could Not Create the SDL_Renderer");
	return m_renderer ? m_renderer.get() : nullptr;
}


void Renderer::SetTextureMgr(const sdl::graphics::TextureMgr* i_textureMgr)
{
	m_textureMgr = i_textureMgr;
}

} //namespace graphics
} // namespace sdl