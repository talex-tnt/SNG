@echo off
rem rmdir /s /q build

set CURRENT_DIR=%cd%
cd ..
set ROOT=%cd%

cd %CURRENT_DIR%
mkdir build-vsc
cd build-vsc

set SNG_LIB_DIR=%ROOT%\libs

set SDL_VERSION=SDL2-2.0.9

set SDL_INCLUDE_PATH=%SNG_LIB_DIR%\%SDL_VERSION%\include

set SDL_LIBRARY_PATH=%SNG_LIB_DIR%\%SDL_VERSION%\build\Release

set SDL_LIBS=%SDL_LIBRARY_PATH%\SDL2.lib;%SDL_LIBRARY_PATH%\SDL2main.lib;Imm32.lib;version.lib


cmake -G "Visual Studio 15 2017 Win64" ../.. -DSDL2_INCLUDE_DIR=%SDL_INCLUDE_PATH% -DSDL2_LIBRARY=%SDL_LIBS%

pause