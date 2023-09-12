#set(CMAKE_TOOLCHAIN_FILE "C:/Program Files/Vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_TOOLCHAIN_FILE "D:/Program Files/Vcpkg/scripts/buildsystems/vcpkg.cmake")

cmake_minimum_required(VERSION 3.25.1)
project(lget)

file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/src/*.c"
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        )

add_compile_definitions("DEBUG=$<CONFIG:Debug>")

find_package(jsoncpp CONFIG REQUIRED)

set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} JsonCpp::JsonCpp)
