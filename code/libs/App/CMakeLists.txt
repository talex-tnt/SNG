cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)

include(utils)

get_folder_name(FOLDER_NAME)
project (${FOLDER_NAME})

collect_files(HEADER_FILES SOURCE_FILES)
group_files("${HEADER_FILES}" "${SOURCE_FILES}")

add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}  
	sub::cpp-utils
	AppIdentifiers
	AppInterfaces
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

