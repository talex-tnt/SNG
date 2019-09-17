set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(App)
add_subdirectory(AppInterfaces)
add_subdirectory(AppIdentifiers)

add_subdirectory(SDLApp)
add_subdirectory(SDLGraphics)
#add_subdirectory(SDLGraphicsTTF)
add_subdirectory(SDLGraphicsImage)
add_subdirectory(SDLGraphicsOpenGL)
add_subdirectory(SDLInterfaces)

add_subdirectory(CppUtils/code)

set_target_properties (App PROPERTIES FOLDER libs/App)
set_target_properties (AppInterfaces-h PROPERTIES FOLDER libs/App)
set_target_properties (AppIdentifiers-h PROPERTIES FOLDER libs/App)

set_target_properties (SDLApp PROPERTIES FOLDER libs/SDL)
set_target_properties (SDLGraphics PROPERTIES FOLDER libs/SDL)
#set_target_properties (SDLGraphicsTTF PROPERTIES FOLDER libs/SDL)
set_target_properties (SDLGraphicsImage PROPERTIES FOLDER libs/SDL)
set_target_properties (SDLGraphicsOpenGL PROPERTIES FOLDER libs/SDL)
set_target_properties (SDLInterfaces-h PROPERTIES FOLDER libs/SDL)

set_target_properties (cpp-utils-h PROPERTIES FOLDER libs)
