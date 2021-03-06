# Clion cmake fileF
cmake_minimum_required(VERSION 2.8.4)
project(FSDL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add here all *.cpp files
set(SOURCE_FILES
    src/entities/base/BaseObject.cpp
    src/entities/Window.cpp
    src/entities/common/Texture.cpp

    src/singletons/Application.cpp
    src/singletons/TextureManager.cpp
    src/singletons/Events.cpp
    src/entities/ele.cpp
    src/entities/elephant.cpp

    src/tests/BaseObjectTest.cpp
    src/tests/WindowTest.cpp
    src/tests/ApplicationTest.cpp
    src/tests/TextureManagerTest.cpp

    src/main.cpp
    )

add_executable(FSDL ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2MIXER_LIBRARIES})
