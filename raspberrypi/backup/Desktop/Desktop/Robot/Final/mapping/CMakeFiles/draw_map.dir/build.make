# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/pi/Desktop/Robot/Final/mapping

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/Robot/Final/mapping

# Include any dependencies generated for this target.
include CMakeFiles/draw_map.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/draw_map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/draw_map.dir/flags.make

CMakeFiles/draw_map.dir/drawMap.cpp.o: CMakeFiles/draw_map.dir/flags.make
CMakeFiles/draw_map.dir/drawMap.cpp.o: drawMap.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/Desktop/Robot/Final/mapping/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/draw_map.dir/drawMap.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/draw_map.dir/drawMap.cpp.o -c /home/pi/Desktop/Robot/Final/mapping/drawMap.cpp

CMakeFiles/draw_map.dir/drawMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw_map.dir/drawMap.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/Desktop/Robot/Final/mapping/drawMap.cpp > CMakeFiles/draw_map.dir/drawMap.cpp.i

CMakeFiles/draw_map.dir/drawMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw_map.dir/drawMap.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/Desktop/Robot/Final/mapping/drawMap.cpp -o CMakeFiles/draw_map.dir/drawMap.cpp.s

CMakeFiles/draw_map.dir/drawMap.cpp.o.requires:
.PHONY : CMakeFiles/draw_map.dir/drawMap.cpp.o.requires

CMakeFiles/draw_map.dir/drawMap.cpp.o.provides: CMakeFiles/draw_map.dir/drawMap.cpp.o.requires
	$(MAKE) -f CMakeFiles/draw_map.dir/build.make CMakeFiles/draw_map.dir/drawMap.cpp.o.provides.build
.PHONY : CMakeFiles/draw_map.dir/drawMap.cpp.o.provides

CMakeFiles/draw_map.dir/drawMap.cpp.o.provides.build: CMakeFiles/draw_map.dir/drawMap.cpp.o

# Object files for target draw_map
draw_map_OBJECTS = \
"CMakeFiles/draw_map.dir/drawMap.cpp.o"

# External object files for target draw_map
draw_map_EXTERNAL_OBJECTS =

draw_map: CMakeFiles/draw_map.dir/drawMap.cpp.o
draw_map: CMakeFiles/draw_map.dir/build.make
draw_map: /opt/vc/lib/libmmal_core.so
draw_map: /opt/vc/lib/libmmal_util.so
draw_map: /opt/vc/lib/libmmal_vc_client.so
draw_map: /opt/vc/lib/libvcos.so
draw_map: /opt/vc/lib/libbcm_host.so
draw_map: CMakeFiles/draw_map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable draw_map"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/draw_map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/draw_map.dir/build: draw_map
.PHONY : CMakeFiles/draw_map.dir/build

CMakeFiles/draw_map.dir/requires: CMakeFiles/draw_map.dir/drawMap.cpp.o.requires
.PHONY : CMakeFiles/draw_map.dir/requires

CMakeFiles/draw_map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/draw_map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/draw_map.dir/clean

CMakeFiles/draw_map.dir/depend:
	cd /home/pi/Desktop/Robot/Final/mapping && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/Robot/Final/mapping /home/pi/Desktop/Robot/Final/mapping /home/pi/Desktop/Robot/Final/mapping /home/pi/Desktop/Robot/Final/mapping /home/pi/Desktop/Robot/Final/mapping/CMakeFiles/draw_map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/draw_map.dir/depend

