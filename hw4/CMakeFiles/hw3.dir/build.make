# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marcus/grive/2018fall/graphics/hw/hw3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcus/grive/2018fall/graphics/hw/hw3

# Include any dependencies generated for this target.
include CMakeFiles/hw3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw3.dir/flags.make

CMakeFiles/hw3.dir/main.cpp.o: CMakeFiles/hw3.dir/flags.make
CMakeFiles/hw3.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3.dir/main.cpp.o -c /home/marcus/grive/2018fall/graphics/hw/hw3/main.cpp

CMakeFiles/hw3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcus/grive/2018fall/graphics/hw/hw3/main.cpp > CMakeFiles/hw3.dir/main.cpp.i

CMakeFiles/hw3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcus/grive/2018fall/graphics/hw/hw3/main.cpp -o CMakeFiles/hw3.dir/main.cpp.s

CMakeFiles/hw3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/hw3.dir/main.cpp.o.requires

CMakeFiles/hw3.dir/main.cpp.o.provides: CMakeFiles/hw3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw3.dir/build.make CMakeFiles/hw3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/hw3.dir/main.cpp.o.provides

CMakeFiles/hw3.dir/main.cpp.o.provides.build: CMakeFiles/hw3.dir/main.cpp.o


CMakeFiles/hw3.dir/Cylinder.cpp.o: CMakeFiles/hw3.dir/flags.make
CMakeFiles/hw3.dir/Cylinder.cpp.o: Cylinder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw3.dir/Cylinder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3.dir/Cylinder.cpp.o -c /home/marcus/grive/2018fall/graphics/hw/hw3/Cylinder.cpp

CMakeFiles/hw3.dir/Cylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3.dir/Cylinder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcus/grive/2018fall/graphics/hw/hw3/Cylinder.cpp > CMakeFiles/hw3.dir/Cylinder.cpp.i

CMakeFiles/hw3.dir/Cylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3.dir/Cylinder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcus/grive/2018fall/graphics/hw/hw3/Cylinder.cpp -o CMakeFiles/hw3.dir/Cylinder.cpp.s

CMakeFiles/hw3.dir/Cylinder.cpp.o.requires:

.PHONY : CMakeFiles/hw3.dir/Cylinder.cpp.o.requires

CMakeFiles/hw3.dir/Cylinder.cpp.o.provides: CMakeFiles/hw3.dir/Cylinder.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw3.dir/build.make CMakeFiles/hw3.dir/Cylinder.cpp.o.provides.build
.PHONY : CMakeFiles/hw3.dir/Cylinder.cpp.o.provides

CMakeFiles/hw3.dir/Cylinder.cpp.o.provides.build: CMakeFiles/hw3.dir/Cylinder.cpp.o


CMakeFiles/hw3.dir/Circle.cpp.o: CMakeFiles/hw3.dir/flags.make
CMakeFiles/hw3.dir/Circle.cpp.o: Circle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw3.dir/Circle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3.dir/Circle.cpp.o -c /home/marcus/grive/2018fall/graphics/hw/hw3/Circle.cpp

CMakeFiles/hw3.dir/Circle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3.dir/Circle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcus/grive/2018fall/graphics/hw/hw3/Circle.cpp > CMakeFiles/hw3.dir/Circle.cpp.i

CMakeFiles/hw3.dir/Circle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3.dir/Circle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcus/grive/2018fall/graphics/hw/hw3/Circle.cpp -o CMakeFiles/hw3.dir/Circle.cpp.s

CMakeFiles/hw3.dir/Circle.cpp.o.requires:

.PHONY : CMakeFiles/hw3.dir/Circle.cpp.o.requires

CMakeFiles/hw3.dir/Circle.cpp.o.provides: CMakeFiles/hw3.dir/Circle.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw3.dir/build.make CMakeFiles/hw3.dir/Circle.cpp.o.provides.build
.PHONY : CMakeFiles/hw3.dir/Circle.cpp.o.provides

CMakeFiles/hw3.dir/Circle.cpp.o.provides.build: CMakeFiles/hw3.dir/Circle.cpp.o


CMakeFiles/hw3.dir/RectangularPrism.cpp.o: CMakeFiles/hw3.dir/flags.make
CMakeFiles/hw3.dir/RectangularPrism.cpp.o: RectangularPrism.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hw3.dir/RectangularPrism.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3.dir/RectangularPrism.cpp.o -c /home/marcus/grive/2018fall/graphics/hw/hw3/RectangularPrism.cpp

CMakeFiles/hw3.dir/RectangularPrism.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3.dir/RectangularPrism.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcus/grive/2018fall/graphics/hw/hw3/RectangularPrism.cpp > CMakeFiles/hw3.dir/RectangularPrism.cpp.i

CMakeFiles/hw3.dir/RectangularPrism.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3.dir/RectangularPrism.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcus/grive/2018fall/graphics/hw/hw3/RectangularPrism.cpp -o CMakeFiles/hw3.dir/RectangularPrism.cpp.s

CMakeFiles/hw3.dir/RectangularPrism.cpp.o.requires:

.PHONY : CMakeFiles/hw3.dir/RectangularPrism.cpp.o.requires

CMakeFiles/hw3.dir/RectangularPrism.cpp.o.provides: CMakeFiles/hw3.dir/RectangularPrism.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw3.dir/build.make CMakeFiles/hw3.dir/RectangularPrism.cpp.o.provides.build
.PHONY : CMakeFiles/hw3.dir/RectangularPrism.cpp.o.provides

CMakeFiles/hw3.dir/RectangularPrism.cpp.o.provides.build: CMakeFiles/hw3.dir/RectangularPrism.cpp.o


CMakeFiles/hw3.dir/Ring.cpp.o: CMakeFiles/hw3.dir/flags.make
CMakeFiles/hw3.dir/Ring.cpp.o: Ring.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/hw3.dir/Ring.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3.dir/Ring.cpp.o -c /home/marcus/grive/2018fall/graphics/hw/hw3/Ring.cpp

CMakeFiles/hw3.dir/Ring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3.dir/Ring.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcus/grive/2018fall/graphics/hw/hw3/Ring.cpp > CMakeFiles/hw3.dir/Ring.cpp.i

CMakeFiles/hw3.dir/Ring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3.dir/Ring.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcus/grive/2018fall/graphics/hw/hw3/Ring.cpp -o CMakeFiles/hw3.dir/Ring.cpp.s

CMakeFiles/hw3.dir/Ring.cpp.o.requires:

.PHONY : CMakeFiles/hw3.dir/Ring.cpp.o.requires

CMakeFiles/hw3.dir/Ring.cpp.o.provides: CMakeFiles/hw3.dir/Ring.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw3.dir/build.make CMakeFiles/hw3.dir/Ring.cpp.o.provides.build
.PHONY : CMakeFiles/hw3.dir/Ring.cpp.o.provides

CMakeFiles/hw3.dir/Ring.cpp.o.provides.build: CMakeFiles/hw3.dir/Ring.cpp.o


CMakeFiles/hw3.dir/FerrisWheel.cpp.o: CMakeFiles/hw3.dir/flags.make
CMakeFiles/hw3.dir/FerrisWheel.cpp.o: FerrisWheel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/hw3.dir/FerrisWheel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3.dir/FerrisWheel.cpp.o -c /home/marcus/grive/2018fall/graphics/hw/hw3/FerrisWheel.cpp

CMakeFiles/hw3.dir/FerrisWheel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3.dir/FerrisWheel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcus/grive/2018fall/graphics/hw/hw3/FerrisWheel.cpp > CMakeFiles/hw3.dir/FerrisWheel.cpp.i

CMakeFiles/hw3.dir/FerrisWheel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3.dir/FerrisWheel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcus/grive/2018fall/graphics/hw/hw3/FerrisWheel.cpp -o CMakeFiles/hw3.dir/FerrisWheel.cpp.s

CMakeFiles/hw3.dir/FerrisWheel.cpp.o.requires:

.PHONY : CMakeFiles/hw3.dir/FerrisWheel.cpp.o.requires

CMakeFiles/hw3.dir/FerrisWheel.cpp.o.provides: CMakeFiles/hw3.dir/FerrisWheel.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw3.dir/build.make CMakeFiles/hw3.dir/FerrisWheel.cpp.o.provides.build
.PHONY : CMakeFiles/hw3.dir/FerrisWheel.cpp.o.provides

CMakeFiles/hw3.dir/FerrisWheel.cpp.o.provides.build: CMakeFiles/hw3.dir/FerrisWheel.cpp.o


CMakeFiles/hw3.dir/Mug.cpp.o: CMakeFiles/hw3.dir/flags.make
CMakeFiles/hw3.dir/Mug.cpp.o: Mug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/hw3.dir/Mug.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3.dir/Mug.cpp.o -c /home/marcus/grive/2018fall/graphics/hw/hw3/Mug.cpp

CMakeFiles/hw3.dir/Mug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3.dir/Mug.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcus/grive/2018fall/graphics/hw/hw3/Mug.cpp > CMakeFiles/hw3.dir/Mug.cpp.i

CMakeFiles/hw3.dir/Mug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3.dir/Mug.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcus/grive/2018fall/graphics/hw/hw3/Mug.cpp -o CMakeFiles/hw3.dir/Mug.cpp.s

CMakeFiles/hw3.dir/Mug.cpp.o.requires:

.PHONY : CMakeFiles/hw3.dir/Mug.cpp.o.requires

CMakeFiles/hw3.dir/Mug.cpp.o.provides: CMakeFiles/hw3.dir/Mug.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw3.dir/build.make CMakeFiles/hw3.dir/Mug.cpp.o.provides.build
.PHONY : CMakeFiles/hw3.dir/Mug.cpp.o.provides

CMakeFiles/hw3.dir/Mug.cpp.o.provides.build: CMakeFiles/hw3.dir/Mug.cpp.o


# Object files for target hw3
hw3_OBJECTS = \
"CMakeFiles/hw3.dir/main.cpp.o" \
"CMakeFiles/hw3.dir/Cylinder.cpp.o" \
"CMakeFiles/hw3.dir/Circle.cpp.o" \
"CMakeFiles/hw3.dir/RectangularPrism.cpp.o" \
"CMakeFiles/hw3.dir/Ring.cpp.o" \
"CMakeFiles/hw3.dir/FerrisWheel.cpp.o" \
"CMakeFiles/hw3.dir/Mug.cpp.o"

# External object files for target hw3
hw3_EXTERNAL_OBJECTS =

hw3: CMakeFiles/hw3.dir/main.cpp.o
hw3: CMakeFiles/hw3.dir/Cylinder.cpp.o
hw3: CMakeFiles/hw3.dir/Circle.cpp.o
hw3: CMakeFiles/hw3.dir/RectangularPrism.cpp.o
hw3: CMakeFiles/hw3.dir/Ring.cpp.o
hw3: CMakeFiles/hw3.dir/FerrisWheel.cpp.o
hw3: CMakeFiles/hw3.dir/Mug.cpp.o
hw3: CMakeFiles/hw3.dir/build.make
hw3: /usr/lib/x86_64-linux-gnu/libGL.so
hw3: /usr/lib/x86_64-linux-gnu/libGLU.so
hw3: /usr/lib/x86_64-linux-gnu/libglut.so
hw3: /usr/lib/x86_64-linux-gnu/libXmu.so
hw3: /usr/lib/x86_64-linux-gnu/libXi.so
hw3: CMakeFiles/hw3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable hw3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw3.dir/build: hw3

.PHONY : CMakeFiles/hw3.dir/build

CMakeFiles/hw3.dir/requires: CMakeFiles/hw3.dir/main.cpp.o.requires
CMakeFiles/hw3.dir/requires: CMakeFiles/hw3.dir/Cylinder.cpp.o.requires
CMakeFiles/hw3.dir/requires: CMakeFiles/hw3.dir/Circle.cpp.o.requires
CMakeFiles/hw3.dir/requires: CMakeFiles/hw3.dir/RectangularPrism.cpp.o.requires
CMakeFiles/hw3.dir/requires: CMakeFiles/hw3.dir/Ring.cpp.o.requires
CMakeFiles/hw3.dir/requires: CMakeFiles/hw3.dir/FerrisWheel.cpp.o.requires
CMakeFiles/hw3.dir/requires: CMakeFiles/hw3.dir/Mug.cpp.o.requires

.PHONY : CMakeFiles/hw3.dir/requires

CMakeFiles/hw3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw3.dir/clean

CMakeFiles/hw3.dir/depend:
	cd /home/marcus/grive/2018fall/graphics/hw/hw3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcus/grive/2018fall/graphics/hw/hw3 /home/marcus/grive/2018fall/graphics/hw/hw3 /home/marcus/grive/2018fall/graphics/hw/hw3 /home/marcus/grive/2018fall/graphics/hw/hw3 /home/marcus/grive/2018fall/graphics/hw/hw3/CMakeFiles/hw3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw3.dir/depend

