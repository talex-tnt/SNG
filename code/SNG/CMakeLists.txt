include(utils)

collect_files(HEADER_FILES SOURCE_FILES)
group_files("${HEADER_FILES}" "${SOURCE_FILES}")

add_executable(${PROJECT_NAME} 
    ${HEADER_FILES}
	${SOURCE_FILES}
)

include_directories(
	${PROJECT_SOURCE_DIR}/code/SNG/include/
)

target_link_libraries(${PROJECT_NAME}
	${SO_LIBRARIES}
	sub::cpp-utils
    App
    SDLApp
    SDLGraphics
)