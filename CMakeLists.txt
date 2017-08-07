cmake_minimum_required(VERSION 2.8)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(METestGame)

# Build the MoleEngine library
set(ME_SOURCE_ROOT ../MoleEngine CACHE PATH "Path to the root directory of the MoleEngine source")
add_subdirectory(${ME_SOURCE_ROOT} engine)

# Find sources, add necessary includes and define the executable
set(EXEC_NAME "METest")
file(GLOB SOURCES src/*.cpp)
include_directories(include ${MoleEngine_INCLUDE_DIRS})
add_executable(${EXEC_NAME} ${SOURCES})

target_link_libraries(${EXEC_NAME} LibMoleEngine)

#automatically copy assets to the build folder
add_custom_command(TARGET ${EXEC_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${PROJECT_SOURCE_DIR}/assets"
	$<TARGET_FILE_DIR:${EXEC_NAME}>/assets)
	
#automatically copy SFML .dlls to binary directory if they haven't been copied yet
set(SFML_BIN_DIR "" CACHE PATH "Path to the SFML .dlls for automatic copying")
if(SFML_BIN_DIR)
add_custom_command(TARGET ${EXEC_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_BIN_DIR}/sfml-audio-$<$<CONFIG:Debug>:d->2.dll $<TARGET_FILE_DIR:${EXEC_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_BIN_DIR}/sfml-graphics-$<$<CONFIG:Debug>:d->2.dll $<TARGET_FILE_DIR:${EXEC_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_BIN_DIR}/sfml-network-$<$<CONFIG:Debug>:d->2.dll $<TARGET_FILE_DIR:${EXEC_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_BIN_DIR}/sfml-system-$<$<CONFIG:Debug>:d->2.dll $<TARGET_FILE_DIR:${EXEC_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_BIN_DIR}/sfml-window-$<$<CONFIG:Debug>:d->2.dll $<TARGET_FILE_DIR:${EXEC_NAME}>
)
endif()
	
	
install(TARGETS ${EXEC_NAME} DESTINATION bin)