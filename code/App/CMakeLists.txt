cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)

project (App)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SOURCE_FILES "source/*.cpp" "source/*.h")


# source_group("HELLO" FILES "D:/_gitarea/cpp/SNG/code/App/include/App/UI/IWindow.h")
create_groups("Header Files" "${CMAKE_CURRENT_SOURCE_DIR}/include" "${HEADER_FILES}")
create_groups("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/source" "${SOURCE_FILES}")

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}  
	sub::cpp-utils
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

