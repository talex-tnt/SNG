**SDL Game Draft**

This project depends on:
- CMake: https://cmake.org/download/
- SDL2-2.0.9: https://www.libsdl.org/download-2.0.php

Please install **CMake** first and download **SDL2-2.0.9**.

The *scripts* folder contains the following scripts:  
*scripts* \ **gen_proj-vsc.bat** generates Visual Studio project files in *scripts* \ **build-vsc**  
*scripts* \ **gen_proj-llvm.bat** generates Visual Studio project files in *scripts* \ **build-llvm**  
*scripts* \ **gen_SDL_proj.bat** generates Visual Studio project files for **SDL2-2.0.9**. Fix the script for supporting a different version.  
*scripts* \ **clean_proj.bat** cleans up *scripts* \ **build-%%%** folders containing the project files.  

The build script expects a folder 
*libs\SDL2-2.0.9* 
containing all the SDL files.
You need to extract SDL there, run *scripts* \ **gen_SDL_proj.bat** open Visual Studio and build the project.

Then create the folder:
*scripts* \ **app**  
(it is set as working directory by cmake)
and copy the **SDL2.dll** file in it after the SDL2-2.0.9 is built.

You can then run:
*scripts* \ **gen_proj-vsc.bat**
to generate the Visual Studio project inside *scripts\build-vsc*
open the solution in it and build it.


If you want to build with **LLVM/Clang**  
please download and install **llvm** pre-built binaries from:  
http://releases.llvm.org/download.html  
and the **LLVM Toolchain Extension** for *Visual Studio 2017*:  
https://marketplace.visualstudio.com/items?itemName=LLVMExtensions.llvm-toolchain  
Then run:  
*scripts* \ **gen_SDL_proj-llvm.bat** that will generates Visual Studio project files under
*scripts* \ **build-llvm** with llvm as target.
