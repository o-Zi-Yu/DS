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
CMAKE_SOURCE_DIR = /mnt/d/a/作业/DS/CW/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/a/作业/DS/CW/lab4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4.dir/flags.make

CMakeFiles/lab4.dir/buggy_lab4.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/buggy_lab4.cpp.o: ../buggy_lab4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/a/作业/DS/CW/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab4.dir/buggy_lab4.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4.dir/buggy_lab4.cpp.o -c /mnt/d/a/作业/DS/CW/lab4/buggy_lab4.cpp

CMakeFiles/lab4.dir/buggy_lab4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/buggy_lab4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/a/作业/DS/CW/lab4/buggy_lab4.cpp > CMakeFiles/lab4.dir/buggy_lab4.cpp.i

CMakeFiles/lab4.dir/buggy_lab4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/buggy_lab4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/a/作业/DS/CW/lab4/buggy_lab4.cpp -o CMakeFiles/lab4.dir/buggy_lab4.cpp.s

CMakeFiles/lab4.dir/buggy_lab4.cpp.o.requires:

.PHONY : CMakeFiles/lab4.dir/buggy_lab4.cpp.o.requires

CMakeFiles/lab4.dir/buggy_lab4.cpp.o.provides: CMakeFiles/lab4.dir/buggy_lab4.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/buggy_lab4.cpp.o.provides.build
.PHONY : CMakeFiles/lab4.dir/buggy_lab4.cpp.o.provides

CMakeFiles/lab4.dir/buggy_lab4.cpp.o.provides.build: CMakeFiles/lab4.dir/buggy_lab4.cpp.o


# Object files for target lab4
lab4_OBJECTS = \
"CMakeFiles/lab4.dir/buggy_lab4.cpp.o"

# External object files for target lab4
lab4_EXTERNAL_OBJECTS =

lab4: CMakeFiles/lab4.dir/buggy_lab4.cpp.o
lab4: CMakeFiles/lab4.dir/build.make
lab4: CMakeFiles/lab4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/a/作业/DS/CW/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4.dir/build: lab4

.PHONY : CMakeFiles/lab4.dir/build

CMakeFiles/lab4.dir/requires: CMakeFiles/lab4.dir/buggy_lab4.cpp.o.requires

.PHONY : CMakeFiles/lab4.dir/requires

CMakeFiles/lab4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab4.dir/clean

CMakeFiles/lab4.dir/depend:
	cd /mnt/d/a/作业/DS/CW/lab4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/a/作业/DS/CW/lab4 /mnt/d/a/作业/DS/CW/lab4 /mnt/d/a/作业/DS/CW/lab4/cmake-build-debug /mnt/d/a/作业/DS/CW/lab4/cmake-build-debug /mnt/d/a/作业/DS/CW/lab4/cmake-build-debug/CMakeFiles/lab4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab4.dir/depend

