cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)

project (SDLApp)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SOURCE_FILES "source/*.cpp")

create_groups("${CMAKE_CURRENT_SOURCE_DIR}/include/SDLApp" "${HEADER_FILES}")
create_groups("${CMAKE_CURRENT_SOURCE_DIR}/source" "${SOURCE_FILES}")

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} 
    ${COMMON_LIBRARIES}
    cpp-utils
    App
)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
    ${COMMON_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)
