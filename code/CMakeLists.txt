# https://stackoverflow.com/questions/31966135/cmake-source-group-not-working-correctly-with-hierarchical-project-setup
function(create_groups current_src_dir files )
    foreach(FILE ${files}) 
        # message("0: ${FILE}")
        get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)     # Get the directory of the source file
        # message("1: ${PARENT_DIR}")
        # message("2: ${current_src_dir}")

        string(REPLACE "${current_src_dir}" "" GROUP "${PARENT_DIR}")     # Remove common directory prefix to make the group
        string(REPLACE "/" "\\" GROUP "${GROUP}")     # Make sure we are using windows slashes
        if ("${FILE}" MATCHES ".*\\.cpp")                # Group into "Source Files" and "Header Files"
           set(GROUP "Source Files${GROUP}")
        elseif("${FILE}" MATCHES ".*\\.h")
           set(GROUP "Header Files${GROUP}")
        endif()
        # message("GROUP: ${GROUP}")
        # message("FILE : ${FILE}")
        source_group("${GROUP}" FILES "${FILE}")
    endforeach()
endfunction()

add_subdirectory(App)
add_subdirectory(SDLApp)
add_subdirectory(SNG)