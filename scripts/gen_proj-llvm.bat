@echo off
rem rmdir /s /q build

set CURRENT_DIR=%cd%
cd ..
set ROOT=%cd%

cd %CURRENT_DIR%
mkdir builds
cd builds
mkdir llvm
cd llvm

set SNG_LIB_DIR=%ROOT%\libs

set SDL_VERSION=SDL2-2.0.9
set SDL_IMAGE_VER=SDL2_image-2.0.4
set GLEW_VERSION=glew-2.1.0

set SDL_INCLUDE_PATH=%SNG_LIB_DIR%\%SDL_VERSION%\include;%SNG_LIB_DIR%\%SDL_IMAGE_VER%
set GLEW_INCLUDE_PATH=%SNG_LIB_DIR%\%GLEW_VERSION%\include

set SDL_LIBRARY_PATH=%SNG_LIB_DIR%\%SDL_VERSION%\build\Release
set SDL_IMAGE_LIB_PATH=%SNG_LIB_DIR%\%SDL_IMAGE_VER%\VisualC\x64\Release
set GLEW_LIBRARY_PATH=%SNG_LIB_DIR%\%GLEW_VERSION%\lib\Release\x64
set GLEW_LIB=%GLEW_LIBRARY_PATH%\glew32.lib;opengl32.lib

set SDL_LIBS=%SDL_LIBRARY_PATH%\SDL2.lib;%SDL_LIBRARY_PATH%\SDL2main.lib;Imm32.lib;version.lib;%SDL_IMAGE_LIB_PATH%\SDL2_image.lib


cmake -G "Visual Studio 15 2017 Win64"^
 ../../..^
 -T llvm^
 -DSDL2_INCLUDE_DIR=%SDL_INCLUDE_PATH%^
 -DSDL2_LIBRARY=%SDL_LIBS%^
 -DGLEW_INCLUDE_DIR=%GLEW_INCLUDE_PATH%^
 -DGLEW_LIBRARY=%GLEW_LIB%

cd %CURRENT_DIR%/cmd
Notification.bat "Visual Studio Solution is Ready" "LLVM Compiler"
rem pause