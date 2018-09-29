# cmake file borrowed from https://gist.github.com/icedraco/3ae34b1917cd4e036b54
# NOTE: IF THIS FAILS, YOU MAY HAVE TO
#       sudo apt-get install libxmu-dev libxi-dev
#       http://ubuntuforums.org/showthread.php?t=1703770

cmake_minimum_required(VERSION 3.10)
project(hw3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

#--- Find GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)


#--- Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)


#--- GL includes
include_directories("/usr/include/GL")

#--- Source files
set(SOURCE_FILES
    main.cpp CSCIx229.h Cylinder.cpp Cylinder.h Circle.cpp Circle.h RectangularPrism.cpp RectangularPrism.h Ring.cpp Ring.h FerrisWheel.cpp FerrisWheel.h Mug.cpp Mug.h)

add_executable(hw3 ${SOURCE_FILES})

target_link_libraries(hw3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
