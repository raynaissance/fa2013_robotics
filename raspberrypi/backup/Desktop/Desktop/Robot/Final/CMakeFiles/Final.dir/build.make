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
CMAKE_SOURCE_DIR = /home/pi/Desktop/Robot/Final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/Robot/Final

# Include any dependencies generated for this target.
include CMakeFiles/Final.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Final.dir/flags.make

CMakeFiles/Final.dir/src/Robot.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/src/Robot.cpp.o: src/Robot.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/Desktop/Robot/Final/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Final.dir/src/Robot.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/src/Robot.cpp.o -c /home/pi/Desktop/Robot/Final/src/Robot.cpp

CMakeFiles/Final.dir/src/Robot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/src/Robot.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/Desktop/Robot/Final/src/Robot.cpp > CMakeFiles/Final.dir/src/Robot.cpp.i

CMakeFiles/Final.dir/src/Robot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/src/Robot.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/Desktop/Robot/Final/src/Robot.cpp -o CMakeFiles/Final.dir/src/Robot.cpp.s

CMakeFiles/Final.dir/src/Robot.cpp.o.requires:
.PHONY : CMakeFiles/Final.dir/src/Robot.cpp.o.requires

CMakeFiles/Final.dir/src/Robot.cpp.o.provides: CMakeFiles/Final.dir/src/Robot.cpp.o.requires
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/src/Robot.cpp.o.provides.build
.PHONY : CMakeFiles/Final.dir/src/Robot.cpp.o.provides

CMakeFiles/Final.dir/src/Robot.cpp.o.provides.build: CMakeFiles/Final.dir/src/Robot.cpp.o

CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o: src/actuators/DCMotor/DCMotor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/Desktop/Robot/Final/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o -c /home/pi/Desktop/Robot/Final/src/actuators/DCMotor/DCMotor.cpp

CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/Desktop/Robot/Final/src/actuators/DCMotor/DCMotor.cpp > CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.i

CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/Desktop/Robot/Final/src/actuators/DCMotor/DCMotor.cpp -o CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.s

CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o.requires:
.PHONY : CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o.requires

CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o.provides: CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o.requires
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o.provides.build
.PHONY : CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o.provides

CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o.provides.build: CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o

CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o: src/actuators/ServoMotor/ServoMotor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/Desktop/Robot/Final/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o -c /home/pi/Desktop/Robot/Final/src/actuators/ServoMotor/ServoMotor.cpp

CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/Desktop/Robot/Final/src/actuators/ServoMotor/ServoMotor.cpp > CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.i

CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/Desktop/Robot/Final/src/actuators/ServoMotor/ServoMotor.cpp -o CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.s

CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o.requires:
.PHONY : CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o.requires

CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o.provides: CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o.requires
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o.provides.build
.PHONY : CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o.provides

CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o.provides.build: CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o

CMakeFiles/Final.dir/src/Agent.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/src/Agent.cpp.o: src/Agent.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/Desktop/Robot/Final/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Final.dir/src/Agent.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/src/Agent.cpp.o -c /home/pi/Desktop/Robot/Final/src/Agent.cpp

CMakeFiles/Final.dir/src/Agent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/src/Agent.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/Desktop/Robot/Final/src/Agent.cpp > CMakeFiles/Final.dir/src/Agent.cpp.i

CMakeFiles/Final.dir/src/Agent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/src/Agent.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/Desktop/Robot/Final/src/Agent.cpp -o CMakeFiles/Final.dir/src/Agent.cpp.s

CMakeFiles/Final.dir/src/Agent.cpp.o.requires:
.PHONY : CMakeFiles/Final.dir/src/Agent.cpp.o.requires

CMakeFiles/Final.dir/src/Agent.cpp.o.provides: CMakeFiles/Final.dir/src/Agent.cpp.o.requires
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/src/Agent.cpp.o.provides.build
.PHONY : CMakeFiles/Final.dir/src/Agent.cpp.o.provides

CMakeFiles/Final.dir/src/Agent.cpp.o.provides.build: CMakeFiles/Final.dir/src/Agent.cpp.o

CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o: src/sensors/SonarSensor/SonarSensor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/Desktop/Robot/Final/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o -c /home/pi/Desktop/Robot/Final/src/sensors/SonarSensor/SonarSensor.cpp

CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/Desktop/Robot/Final/src/sensors/SonarSensor/SonarSensor.cpp > CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.i

CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/Desktop/Robot/Final/src/sensors/SonarSensor/SonarSensor.cpp -o CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.s

CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o.requires:
.PHONY : CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o.requires

CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o.provides: CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o.requires
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o.provides.build
.PHONY : CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o.provides

CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o.provides.build: CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o

# Object files for target Final
Final_OBJECTS = \
"CMakeFiles/Final.dir/src/Robot.cpp.o" \
"CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o" \
"CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o" \
"CMakeFiles/Final.dir/src/Agent.cpp.o" \
"CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o"

# External object files for target Final
Final_EXTERNAL_OBJECTS =

Final: CMakeFiles/Final.dir/src/Robot.cpp.o
Final: CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o
Final: CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o
Final: CMakeFiles/Final.dir/src/Agent.cpp.o
Final: CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o
Final: CMakeFiles/Final.dir/build.make
Final: /opt/vc/lib/libmmal_core.so
Final: /opt/vc/lib/libmmal_util.so
Final: /opt/vc/lib/libmmal_vc_client.so
Final: /opt/vc/lib/libvcos.so
Final: /opt/vc/lib/libbcm_host.so
Final: CMakeFiles/Final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Final"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Final.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Final.dir/build: Final
.PHONY : CMakeFiles/Final.dir/build

CMakeFiles/Final.dir/requires: CMakeFiles/Final.dir/src/Robot.cpp.o.requires
CMakeFiles/Final.dir/requires: CMakeFiles/Final.dir/src/actuators/DCMotor/DCMotor.cpp.o.requires
CMakeFiles/Final.dir/requires: CMakeFiles/Final.dir/src/actuators/ServoMotor/ServoMotor.cpp.o.requires
CMakeFiles/Final.dir/requires: CMakeFiles/Final.dir/src/Agent.cpp.o.requires
CMakeFiles/Final.dir/requires: CMakeFiles/Final.dir/src/sensors/SonarSensor/SonarSensor.cpp.o.requires
.PHONY : CMakeFiles/Final.dir/requires

CMakeFiles/Final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Final.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Final.dir/clean

CMakeFiles/Final.dir/depend:
	cd /home/pi/Desktop/Robot/Final && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/Robot/Final /home/pi/Desktop/Robot/Final /home/pi/Desktop/Robot/Final /home/pi/Desktop/Robot/Final /home/pi/Desktop/Robot/Final/CMakeFiles/Final.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Final.dir/depend
