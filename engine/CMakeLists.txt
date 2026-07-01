file(GLOB ENGINE_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
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