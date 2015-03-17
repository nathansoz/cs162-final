cmake_minimum_required(VERSION 2.8.4)
project(cs162-final)

find_package(Boost)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

file(GLOB WORLD "./include/world/*.cpp")
file(GLOB CREATURES "./include/creatures/*.cpp")
file(GLOB SOZLIBS "./include/SozLibs/*.cpp")
file(GLOB ROOMS "./include/rooms/*.cpp")
file(GLOB PLAYER "./include/player/*.cpp")

ADD_LIBRARY(world ${WORLD})
ADD_LIBRARY(creatures ${CREATURES})
ADD_LIBRARY(rooms ${ROOMS})
ADD_LIBRARY(sozlibs ${SOZLIBS})
ADD_LIBRARY(player ${PLAYER})

set(cs162_final_FILES
    main.cpp
)

add_executable(final ${cs162_final_FILES})
TARGET_LINK_LIBRARIES(sozlibs player)
TARGET_LINK_LIBRARIES(creatures sozlibs)
TARGET_LINK_LIBRARIES(rooms creatures)
TARGET_LINK_LIBRARIES(world rooms)
TARGET_LINK_LIBRARIES(final world)