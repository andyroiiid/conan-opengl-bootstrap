cmake_minimum_required(VERSION 3.12)
project(conan_opengl_bootstrap)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

# install dependencies with `conan install . -s build_type=Debug --install-folder=cmake-build-debug --build=outdated`
# or `conan install . -s build_type=Release --install-folder=cmake-build-release --build=outdated`

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(conan_opengl_bootstrap ${SOURCE_FILES})

target_link_libraries(conan_opengl_bootstrap ${CONAN_LIBS})