cmake_minimum_required(VERSION 3.5...3.25.1)

set(CMAKE_TOOLCHAIN_FILE "D:/Program Files/Vcpkg/scripts/buildsystems/vcpkg.cmake")

project(lget)

set(SOURCE_FILES ./src/main.cpp)

add_compile_definitions("DEBUG=$<CONFIG:Debug>")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(jsoncpp CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} jsoncpp_lib JsonCpp::JsonCpp)
