#pragma once
#include "App/Interfaces/Graphics/ITextureMgr.h"
#include "App/Identifiers.h"

#include <unordered_map>
#include <memory>

namespace app
{
namespace graphics
{
class ITexture;
}
}

namespace sdl
{
namespace graphics
{
class Renderer;
class Texture;
class SurfaceMgr;

class TextureMgr : public app::graphics::ITextureMgr
{
public:
	TextureMgr(SurfaceMgr& i_surfaceMgr, Renderer& i_renderer);
	~TextureMgr();

	TextureMgr(const TextureMgr&) = delete;
	TextureMgr(TextureMgr&&) = delete;

	TextureMgr& operator=(const TextureMgr&) = delete;
	TextureMgr& operator=(TextureMgr&&) = delete;

	TextureId CreateTexture(TexturePath i_path) override;
	TextureId CreateTexture(SurfaceId i_surfaceId) override;

	const Texture* FindTextureById(TextureId i_textureId) const;
	Texture* FindTextureById(TextureId i_textureId);

private:
	bool InitImageExt();
	Renderer& m_renderer;
	SurfaceMgr& m_surfaceMgr;

	using TexturePtr = std::unique_ptr<Texture>;
	using TextureMap = std::unordered_map<TextureId, TexturePtr, TextureId::Hasher>;
	TextureMap m_textures;
};

}
}