#include "Game.h"
#include "GameContext.h"

#include "Graphics/RenderContext.h"
#include "App/Interfaces/Graphics/ITextureMgr.h"
#include "App/Interfaces/Graphics/IRenderer2D.h"
#include "App/Interfaces/Graphics/IImageSurfaceLoader.h"

namespace sng
{

Game::Game()
{

}

Game::~Game() = default;

bool Game::OnInit(std::unique_ptr<GameContext> i_context)
{
	m_context = std::move(i_context);
	//app::graphics::ITextureMgr& textureMgr = m_context->GetRenderContext().GetTextureMgr();
	//m_textureId = textureMgr.CreateTexture(TexturePath("images/SDL_Logo.png"));
	//m_textureId = textureMgr.CreateTexture(TexturePath("images/Placeholder.bmp"));
	//m_textureId = textureMgr.CreateTexture(TexturePath("images/Placeholder.png"));
	//m_textureId = textureMgr.CreateTexture(TexturePath("images/watermark.png"));

	SurfaceId surfaceId = m_context->GetSurfaceImageLoader().LoadSurface(SurfacePath("images/watermark.png"));
	m_textureId = m_context->GetRenderContext().GetTextureMgr().CreateTexture(surfaceId);
	m_context->GetSurfaceImageLoader().UnloadSurface(surfaceId);

	return true;
}

bool Game::OnInit()
{
	return true;
}

void Game::OnUpdate(std::chrono::milliseconds i_deltaTime)
{

}

void Game::OnRender()
{
	m_context->GetRenderContext().GetRenderer().RenderTexture(m_textureId, 0u, 0u);
}

}