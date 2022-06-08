cmake_minimum_required(VERSION 3.16)
project(ft_newton)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(glfw/include)

IF(APPLE) # Mac
    IF (CMAKE_OSX_ARCHITECTURES==x86_64)
        link_directories(glfw/mac/lib-x86_64)
    ELSEIF(CMAKE_OSX_ARCHITECTURES==arm64)
        link_directories(glfw/mac/lib-arm64)
    ELSE()
       link_directories(glfw/mac/lib-universal)
    ENDIF()
ELSEIF(UNIX) # Linux
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    link_directories(glfw/unix)
ELSEIF(WIN32) # Windows
    link_directories(glfw/win) # Windows
ENDIF()

add_executable(ft_newton
        glad/glad.c
        src/main.cpp
        src/scene.cpp
        src/object.cpp
        src/shader.cpp
        include/scene.h
        include/object.h
        include/shader.h
        )

find_package(OpenGL REQUIRED)

IF(APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    target_link_libraries(ft_newton "libglfw3.a" ${OPENGL_LIBRARIES} ${COCOA_LIBRARY} ${IOKIT_LIBRARY})
ELSEIF(UNIX) # Linux
    target_link_libraries(ft_newton PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS})
ELSEIF(WIN32) # Windows
    target_link_libraries(ft_newton "libglfw3.a" ${OPENGL_LIBRARIES})
ENDIF ()