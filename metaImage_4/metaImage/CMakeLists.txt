cmake_minimum_required(VERSION 3.5)

project(metaImage)


    add_library(library STATIC
            src/create.cpp
            src/read.cpp
            src/tmp.cpp
            #
        )
 
    target_include_directories(library
            PUBLIC
            ${PROJECT_SOURCE_DIR}/lib
        )

    add_executable(main
            src/main.cpp
        )


target_link_libraries(main
        PRIVATE
        library
)


