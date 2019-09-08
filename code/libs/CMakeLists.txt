set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(App)
add_subdirectory(SDLApp)

set_target_properties (App PROPERTIES FOLDER libs)
set_target_properties (SDLApp PROPERTIES FOLDER libs)