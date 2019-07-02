

file(GLOB_RECURSE SRC_ROOT
    "source/*.cpp"
    "include/*.h"
)

# https://stackoverflow.com/questions/31966135/cmake-source-group-not-working-correctly-with-hierarchical-project-setup
foreach(FILE ${SRC_ROOT}) 
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)     # Get the directory of the source file
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")     # Remove common directory prefix to make the group
    string(REPLACE "/" "\\" GROUP "${GROUP}")     # Make sure we are using windows slashes
    if ("${FILE}" MATCHES ".*\\.cpp")			     # Group into "Source Files" and "Header Files"
       set(GROUP "Source Files${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
       set(GROUP "Header Files${GROUP}")
    endif()
    source_group("${GROUP}" FILES "${FILE}")
endforeach()


add_executable(${PROJECT_NAME} 
	${SRC_ROOT}
)

include_directories(
	${COMMON_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/code/include/
)

target_link_libraries(${PROJECT_NAME} 
	${COMMON_LIBRARIES}
	sub::cpp-utils
)