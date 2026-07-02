file(GLOB GAME_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    src/scenes/*.cpp
)

add_library(Game ${GAME_SOURCES})

target_include_directories(Game
    PUBLIC
        include
)

target_link_libraries(Game
    PUBLIC
        Engine
)