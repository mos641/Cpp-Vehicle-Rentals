# CMakeList.txt : CMake project for FinalProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("FinalProject")

add_definitions( -D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)

# Add source to this project's executable.
add_executable (FinalProject "FinalProject.cpp" "FinalProject.h")

target_include_directories(FinalProject PUBLIC "..\\..\\nana\\include")
target_link_libraries(FinalProject "nana_v143_Debug_x64")
target_link_directories(FinalProject PUBLIC "..\\..\\nana\\build\\bin")
