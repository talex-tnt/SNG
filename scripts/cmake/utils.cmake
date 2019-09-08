# https://stackoverflow.com/questions/31966135/cmake-source-group-not-working-correctly-with-hierarchical-project-setup
function(create_groups group_name current_src_dir files )
    foreach(FILE ${files}) 
        # message("0: ${FILE}")
        get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)     # Get the directory of the source file
        # message("1: ${PARENT_DIR}")
        # message("2: ${current_src_dir}")

        string(REPLACE "${current_src_dir}" "" GROUP "${PARENT_DIR}")     # Remove common directory prefix to make the group
        string(REPLACE "/" "\\" GROUP "${GROUP}")     # Make sure we are using windows slashes
        set(GROUP "${group_name}${GROUP}")
        # message("GROUP: ${GROUP}")
        # message("FILE : ${FILE}")
        source_group("${GROUP}" FILES "${FILE}")
    endforeach()
endfunction()

function(get_folder_name folder_name)
    get_filename_component(name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    set (${folder_name} ${name} PARENT_SCOPE)
endfunction()

