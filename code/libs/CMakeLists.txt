set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(App)
add_subdirectory(SDLApp)
add_subdirectory(SDLGraphics)
add_subdirectory(SDLInterfaces)
add_subdirectory(CppUtils/code)

set_target_properties (App PROPERTIES FOLDER libs)
set_target_properties (SDLApp PROPERTIES FOLDER libs)
set_target_properties (SDLGraphics PROPERTIES FOLDER libs)
set_target_properties (SDLInterfaces-h PROPERTIES FOLDER libs)
set_target_properties (cpp-utils-h PROPERTIES FOLDER libs)
