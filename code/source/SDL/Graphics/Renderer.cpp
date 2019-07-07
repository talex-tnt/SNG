#include "SDL/Graphics/Renderer.h"
#include "cpp-utils/Assert.h"
#include "SDL_render.h"

#include "SDL/UI/Window.h"

#include "App/Graphics/ITexture.h"


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

void Renderer::Render(const app::graphics::ITexture& i_texture) const
{
	SDL_RenderClear(m_renderer.get());
	i_texture.Render(0, 0);
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

Renderer::~Renderer() = default;

} //namespace graphics
} // namespace sdl
