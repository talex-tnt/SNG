cmake_minimum_required(VERSION 3.7)

project(sng)



set(COMMON_INCLUDE_DIRS
    ${SDL2_INCLUDE_DIR}
)

set(COMMON_LIBRARIES
	${SDL2_LIBRARY}
)
if(MSVC)
    LIST(APPEND COMMON_LIBRARIES
        winmm
    )
endif()

add_subdirectory(libs/cpp-utils/code)
add_subdirectory(code)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(TARGET  ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/app")





