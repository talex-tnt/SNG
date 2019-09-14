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

class TextureMgr : public app::graphics::ITextureMgr
{
public:
	TextureMgr(sdl::graphics::Renderer& i_renderer);
	~TextureMgr();

	TextureMgr(const TextureMgr&) = delete;
	TextureMgr(TextureMgr&&) = delete;

	TextureMgr& operator=(const TextureMgr&) = delete;
	TextureMgr& operator=(TextureMgr&&) = delete;

	TextureId CreateTexture(TexturePath i_path) override;


	const sdl::graphics::Texture* _FindTextureById(TextureId i_textureId) const;
	sdl::graphics::Texture* _FindTextureById(TextureId i_textureId);

private:
	sdl::graphics::Renderer& m_renderer;
	bool InitImageExt();

	using TexturePtr = std::unique_ptr<sdl::graphics::Texture>;
	using TextureMap = std::unordered_map<TextureId, TexturePtr, TextureId::Hasher>;
	TextureMap m_textures;

};

}
}