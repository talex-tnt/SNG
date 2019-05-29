cmake_minimum_required(VERSION 3.7)

project(sng)

add_executable(${PROJECT_NAME} code/source/main.cpp)

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


include_directories(
	${COMMON_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} 
	${COMMON_LIBRARIES}
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})


