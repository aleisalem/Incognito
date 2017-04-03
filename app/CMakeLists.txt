cmake_minimum_required(VERSION 3.4.1)

add_library(
             secret-keeper

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/secret-keeper.cpp )

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( # Specifies the target library.
                       secret-keeper

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
