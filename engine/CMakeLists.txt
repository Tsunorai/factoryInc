file(GLOB ENGINE_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    src/command/*.cpp
    src/input/*.cpp
    src/render/*.cpp
    src/struct/*.cpp
    src/scene/*.cpp
)

add_library(Engine ${ENGINE_SOURCES})

target_include_directories(Engine
    PUBLIC
        include
)

find_package(raylib REQUIRED)

target_link_libraries(Engine
    PUBLIC
        raylib
)