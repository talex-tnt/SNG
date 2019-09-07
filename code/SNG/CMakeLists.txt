file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SOURCE_FILES "source/*.cpp" "source/*.h")

include(utils)

add_executable(${PROJECT_NAME} 
    ${HEADER_FILES}
	${SOURCE_FILES}
)

create_groups("Header Files" "${CMAKE_CURRENT_SOURCE_DIR}/include" "${HEADER_FILES}")
create_groups("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/source" "${SOURCE_FILES}")

include_directories(
	${PROJECT_SOURCE_DIR}/code/SNG/include/
)

target_link_libraries(${PROJECT_NAME}
	${SO_LIBRARIES}
	sub::cpp-utils
    App
    SDLApp
)