cmake_minimum_required(VERSION 2.8.4)
project(cs162-final)

find_package(Boost)

include_directories("${ROOT_SOURCE_DIR}/thirdparty/rapidjson")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(cs162_final_FILES
)

add_executable(final ${cs162_final_FILES} Room.cpp Room.h main.cpp)