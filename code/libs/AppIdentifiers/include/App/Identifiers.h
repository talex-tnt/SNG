#pragma once

#include <cpp-utils/Identifier.h>
#include <string>

DEFINE_IDENTIFIER(TexturePath, std::string);
DEFINE_IDENTIFIER(SurfacePath, std::string);
DEFINE_IDENTIFIER(TTFSurfaceText, std::string);

DEFINE_IDENTIFIER_WITH_INVALID_VALUE(TextureId, std::size_t, std::numeric_limits<std::size_t>::max());
DEFINE_IDENTIFIER_WITH_INVALID_VALUE(SurfaceId, std::size_t, std::numeric_limits<std::size_t>::max());


