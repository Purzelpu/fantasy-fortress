cmake_minimum_required(VERSION 3.0)

project(WanderingDwarfs VERSION 0.1)

configure_file(version.h.in version.h)
add_executable(start Action.cpp Bush.cpp Coordinate.cpp CursesOutput.cpp
	Dwarf.cpp GetJobAction.cpp GrowBerries.cpp Job.cpp Move.cpp start.cpp
	TakeBerries.cpp Work.cpp World.cpp)


target_include_directories(start PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(start PRIVATE ncurses tinfo)

set(CMAKE_EXPORT_COMPILE_COMMANDS "on")
#message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")
