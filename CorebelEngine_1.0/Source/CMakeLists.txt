add_library(Core
    Core/Engine.cpp
)

add_executable(CorebelEngine
    main.cpp
)

target_link_libraries(CorebelEngine Core)
