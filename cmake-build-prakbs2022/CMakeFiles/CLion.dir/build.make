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
CMAKE_SOURCE_DIR = /root/temp/PrakBS21

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/temp/PrakBS21/cmake-build-prakbs2022

# Include any dependencies generated for this target.
include CMakeFiles/CLion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CLion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLion.dir/flags.make

CMakeFiles/CLion.dir/main.c.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/temp/PrakBS21/cmake-build-prakbs2022/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CLion.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CLion.dir/main.c.o   -c /root/temp/PrakBS21/main.c

CMakeFiles/CLion.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CLion.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/temp/PrakBS21/main.c > CMakeFiles/CLion.dir/main.c.i

CMakeFiles/CLion.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CLion.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/temp/PrakBS21/main.c -o CMakeFiles/CLion.dir/main.c.s

CMakeFiles/CLion.dir/main.c.o.requires:

.PHONY : CMakeFiles/CLion.dir/main.c.o.requires

CMakeFiles/CLion.dir/main.c.o.provides: CMakeFiles/CLion.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/CLion.dir/build.make CMakeFiles/CLion.dir/main.c.o.provides.build
.PHONY : CMakeFiles/CLion.dir/main.c.o.provides

CMakeFiles/CLion.dir/main.c.o.provides.build: CMakeFiles/CLion.dir/main.c.o


# Object files for target CLion
CLion_OBJECTS = \
"CMakeFiles/CLion.dir/main.c.o"

# External object files for target CLion
CLion_EXTERNAL_OBJECTS =

CLion: CMakeFiles/CLion.dir/main.c.o
CLion: CMakeFiles/CLion.dir/build.make
CLion: CMakeFiles/CLion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/temp/PrakBS21/cmake-build-prakbs2022/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable CLion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CLion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLion.dir/build: CLion

.PHONY : CMakeFiles/CLion.dir/build

CMakeFiles/CLion.dir/requires: CMakeFiles/CLion.dir/main.c.o.requires

.PHONY : CMakeFiles/CLion.dir/requires

CMakeFiles/CLion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CLion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CLion.dir/clean

CMakeFiles/CLion.dir/depend:
	cd /root/temp/PrakBS21/cmake-build-prakbs2022 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/temp/PrakBS21 /root/temp/PrakBS21 /root/temp/PrakBS21/cmake-build-prakbs2022 /root/temp/PrakBS21/cmake-build-prakbs2022 /root/temp/PrakBS21/cmake-build-prakbs2022/CMakeFiles/CLion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CLion.dir/depend

