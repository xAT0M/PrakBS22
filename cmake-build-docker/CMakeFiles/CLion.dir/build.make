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
CMAKE_SOURCE_DIR = /Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Server/cmake-build-docker

# Include any dependencies generated for this target.
include CMakeFiles/CLion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CLion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLion.dir/flags.make

CMakeFiles/CLion.dir/main.c.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Server/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CLion.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CLion.dir/main.c.o   -c /Server/main.c

CMakeFiles/CLion.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CLion.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Server/main.c > CMakeFiles/CLion.dir/main.c.i

CMakeFiles/CLion.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CLion.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Server/main.c -o CMakeFiles/CLion.dir/main.c.s

CMakeFiles/CLion.dir/main.c.o.requires:

.PHONY : CMakeFiles/CLion.dir/main.c.o.requires

CMakeFiles/CLion.dir/main.c.o.provides: CMakeFiles/CLion.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/CLion.dir/build.make CMakeFiles/CLion.dir/main.c.o.provides.build
.PHONY : CMakeFiles/CLion.dir/main.c.o.provides

CMakeFiles/CLion.dir/main.c.o.provides.build: CMakeFiles/CLion.dir/main.c.o


CMakeFiles/CLion.dir/KeyValue.c.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/KeyValue.c.o: ../KeyValue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Server/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CLion.dir/KeyValue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CLion.dir/KeyValue.c.o   -c /Server/KeyValue.c

CMakeFiles/CLion.dir/KeyValue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CLion.dir/KeyValue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Server/KeyValue.c > CMakeFiles/CLion.dir/KeyValue.c.i

CMakeFiles/CLion.dir/KeyValue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CLion.dir/KeyValue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Server/KeyValue.c -o CMakeFiles/CLion.dir/KeyValue.c.s

CMakeFiles/CLion.dir/KeyValue.c.o.requires:

.PHONY : CMakeFiles/CLion.dir/KeyValue.c.o.requires

CMakeFiles/CLion.dir/KeyValue.c.o.provides: CMakeFiles/CLion.dir/KeyValue.c.o.requires
	$(MAKE) -f CMakeFiles/CLion.dir/build.make CMakeFiles/CLion.dir/KeyValue.c.o.provides.build
.PHONY : CMakeFiles/CLion.dir/KeyValue.c.o.provides

CMakeFiles/CLion.dir/KeyValue.c.o.provides.build: CMakeFiles/CLion.dir/KeyValue.c.o


CMakeFiles/CLion.dir/sub.c.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/sub.c.o: ../sub.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Server/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/CLion.dir/sub.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CLion.dir/sub.c.o   -c /Server/sub.c

CMakeFiles/CLion.dir/sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CLion.dir/sub.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Server/sub.c > CMakeFiles/CLion.dir/sub.c.i

CMakeFiles/CLion.dir/sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CLion.dir/sub.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Server/sub.c -o CMakeFiles/CLion.dir/sub.c.s

CMakeFiles/CLion.dir/sub.c.o.requires:

.PHONY : CMakeFiles/CLion.dir/sub.c.o.requires

CMakeFiles/CLion.dir/sub.c.o.provides: CMakeFiles/CLion.dir/sub.c.o.requires
	$(MAKE) -f CMakeFiles/CLion.dir/build.make CMakeFiles/CLion.dir/sub.c.o.provides.build
.PHONY : CMakeFiles/CLion.dir/sub.c.o.provides

CMakeFiles/CLion.dir/sub.c.o.provides.build: CMakeFiles/CLion.dir/sub.c.o


# Object files for target CLion
CLion_OBJECTS = \
"CMakeFiles/CLion.dir/main.c.o" \
"CMakeFiles/CLion.dir/KeyValue.c.o" \
"CMakeFiles/CLion.dir/sub.c.o"

# External object files for target CLion
CLion_EXTERNAL_OBJECTS =

CLion: CMakeFiles/CLion.dir/main.c.o
CLion: CMakeFiles/CLion.dir/KeyValue.c.o
CLion: CMakeFiles/CLion.dir/sub.c.o
CLion: CMakeFiles/CLion.dir/build.make
CLion: CMakeFiles/CLion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Server/cmake-build-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable CLion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CLion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLion.dir/build: CLion

.PHONY : CMakeFiles/CLion.dir/build

CMakeFiles/CLion.dir/requires: CMakeFiles/CLion.dir/main.c.o.requires
CMakeFiles/CLion.dir/requires: CMakeFiles/CLion.dir/KeyValue.c.o.requires
CMakeFiles/CLion.dir/requires: CMakeFiles/CLion.dir/sub.c.o.requires

.PHONY : CMakeFiles/CLion.dir/requires

CMakeFiles/CLion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CLion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CLion.dir/clean

CMakeFiles/CLion.dir/depend:
	cd /Server/cmake-build-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Server /Server /Server/cmake-build-docker /Server/cmake-build-docker /Server/cmake-build-docker/CMakeFiles/CLion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CLion.dir/depend

