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
CMAKE_SOURCE_DIR = /mnt/d/a/作业/DS/hw2/abc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/a/作业/DS/hw2/abc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/abc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/abc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/abc.dir/flags.make

CMakeFiles/abc.dir/decath.cpp.o: CMakeFiles/abc.dir/flags.make
CMakeFiles/abc.dir/decath.cpp.o: ../decath.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/a/作业/DS/hw2/abc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/abc.dir/decath.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abc.dir/decath.cpp.o -c /mnt/d/a/作业/DS/hw2/abc/decath.cpp

CMakeFiles/abc.dir/decath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abc.dir/decath.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/a/作业/DS/hw2/abc/decath.cpp > CMakeFiles/abc.dir/decath.cpp.i

CMakeFiles/abc.dir/decath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abc.dir/decath.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/a/作业/DS/hw2/abc/decath.cpp -o CMakeFiles/abc.dir/decath.cpp.s

CMakeFiles/abc.dir/decath.cpp.o.requires:

.PHONY : CMakeFiles/abc.dir/decath.cpp.o.requires

CMakeFiles/abc.dir/decath.cpp.o.provides: CMakeFiles/abc.dir/decath.cpp.o.requires
	$(MAKE) -f CMakeFiles/abc.dir/build.make CMakeFiles/abc.dir/decath.cpp.o.provides.build
.PHONY : CMakeFiles/abc.dir/decath.cpp.o.provides

CMakeFiles/abc.dir/decath.cpp.o.provides.build: CMakeFiles/abc.dir/decath.cpp.o


CMakeFiles/abc.dir/decath_main.cpp.o: CMakeFiles/abc.dir/flags.make
CMakeFiles/abc.dir/decath_main.cpp.o: ../decath_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/a/作业/DS/hw2/abc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/abc.dir/decath_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abc.dir/decath_main.cpp.o -c /mnt/d/a/作业/DS/hw2/abc/decath_main.cpp

CMakeFiles/abc.dir/decath_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abc.dir/decath_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/a/作业/DS/hw2/abc/decath_main.cpp > CMakeFiles/abc.dir/decath_main.cpp.i

CMakeFiles/abc.dir/decath_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abc.dir/decath_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/a/作业/DS/hw2/abc/decath_main.cpp -o CMakeFiles/abc.dir/decath_main.cpp.s

CMakeFiles/abc.dir/decath_main.cpp.o.requires:

.PHONY : CMakeFiles/abc.dir/decath_main.cpp.o.requires

CMakeFiles/abc.dir/decath_main.cpp.o.provides: CMakeFiles/abc.dir/decath_main.cpp.o.requires
	$(MAKE) -f CMakeFiles/abc.dir/build.make CMakeFiles/abc.dir/decath_main.cpp.o.provides.build
.PHONY : CMakeFiles/abc.dir/decath_main.cpp.o.provides

CMakeFiles/abc.dir/decath_main.cpp.o.provides.build: CMakeFiles/abc.dir/decath_main.cpp.o


# Object files for target abc
abc_OBJECTS = \
"CMakeFiles/abc.dir/decath.cpp.o" \
"CMakeFiles/abc.dir/decath_main.cpp.o"

# External object files for target abc
abc_EXTERNAL_OBJECTS =

abc: CMakeFiles/abc.dir/decath.cpp.o
abc: CMakeFiles/abc.dir/decath_main.cpp.o
abc: CMakeFiles/abc.dir/build.make
abc: CMakeFiles/abc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/a/作业/DS/hw2/abc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable abc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/abc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/abc.dir/build: abc

.PHONY : CMakeFiles/abc.dir/build

CMakeFiles/abc.dir/requires: CMakeFiles/abc.dir/decath.cpp.o.requires
CMakeFiles/abc.dir/requires: CMakeFiles/abc.dir/decath_main.cpp.o.requires

.PHONY : CMakeFiles/abc.dir/requires

CMakeFiles/abc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/abc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/abc.dir/clean

CMakeFiles/abc.dir/depend:
	cd /mnt/d/a/作业/DS/hw2/abc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/a/作业/DS/hw2/abc /mnt/d/a/作业/DS/hw2/abc /mnt/d/a/作业/DS/hw2/abc/cmake-build-debug /mnt/d/a/作业/DS/hw2/abc/cmake-build-debug /mnt/d/a/作业/DS/hw2/abc/cmake-build-debug/CMakeFiles/abc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/abc.dir/depend

