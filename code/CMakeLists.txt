
file(GLOB_RECURSE SRC_SDL
    "source/SDL/*.cpp"
    "include/SDL/*.h"
)
add_library(SDL ${SRC_SDL})
source_group("SDL" FILES ${SRC_SDL})
target_link_libraries(SDL
	${COMMON_LIBRARIES}
	sub::cpp-utils
)



add_executable(${PROJECT_NAME} 
	"source/main.cpp" 
)

include_directories(
	${COMMON_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/code/include/
)

target_link_libraries(${PROJECT_NAME} 
	${COMMON_LIBRARIES}
	sub::cpp-utils
	SDL
)