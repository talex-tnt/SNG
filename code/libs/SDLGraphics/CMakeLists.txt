cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)

include(utils)

get_folder_name(FOLDER_NAME)
project (${FOLDER_NAME})

file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SOURCE_FILES "source/*.cpp" "source/*.h")

create_groups("Header Files" "${CMAKE_CURRENT_SOURCE_DIR}/include" "${HEADER_FILES}")
create_groups("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/source" "${SOURCE_FILES}")

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} 
   	${SDL2_LIBRARY}
    cpp-utils
    App
    SDLInterfaces
)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
    ${SDL2_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/include
)
