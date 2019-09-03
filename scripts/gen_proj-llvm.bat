@echo off
rem rmdir /s /q build

set CURRENT_DIR=%cd%
cd ..
set ROOT=%cd%

cd %CURRENT_DIR%
mkdir build-llvm
cd build-llvm

set SNG_LIB_DIR=%ROOT%\libs

set SDL_VERSION=SDL2-2.0.9
set SDL_IMAGE_VER=SDL2_image-2.0.4

set SDL_INCLUDE_PATH=%SNG_LIB_DIR%\%SDL_VERSION%\include;%SNG_LIB_DIR%\%SDL_IMAGE_VER%

set SDL_LIBRARY_PATH=%SNG_LIB_DIR%\%SDL_VERSION%\build\Release
set SDL_IMAGE_LIB_PATH=%SNG_LIB_DIR%\%SDL_IMAGE_VER%\VisualC\x64\Release

set SDL_LIBS=%SDL_LIBRARY_PATH%\SDL2.lib;%SDL_LIBRARY_PATH%\SDL2main.lib;Imm32.lib;version.lib;%SDL_IMAGE_LIB_PATH%\SDL2_image.lib


cmake -G "Visual Studio 15 2017 Win64" ../.. -T llvm -DSDL2_INCLUDE_DIR=%SDL_INCLUDE_PATH% -DSDL2_LIBRARY=%SDL_LIBS%

pause