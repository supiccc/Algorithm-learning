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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/suoiccc/development/Algorithm/algorithms_toy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/suoiccc/development/Algorithm/algorithms_toy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mergesortClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mergesortClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mergesortClient.dir/flags.make

CMakeFiles/mergesortClient.dir/client/main.cpp.o: CMakeFiles/mergesortClient.dir/flags.make
CMakeFiles/mergesortClient.dir/client/main.cpp.o: ../client/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/suoiccc/development/Algorithm/algorithms_toy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mergesortClient.dir/client/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mergesortClient.dir/client/main.cpp.o -c /Users/suoiccc/development/Algorithm/algorithms_toy/client/main.cpp

CMakeFiles/mergesortClient.dir/client/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mergesortClient.dir/client/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/suoiccc/development/Algorithm/algorithms_toy/client/main.cpp > CMakeFiles/mergesortClient.dir/client/main.cpp.i

CMakeFiles/mergesortClient.dir/client/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mergesortClient.dir/client/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/suoiccc/development/Algorithm/algorithms_toy/client/main.cpp -o CMakeFiles/mergesortClient.dir/client/main.cpp.s

CMakeFiles/mergesortClient.dir/client/main.cpp.o.requires:

.PHONY : CMakeFiles/mergesortClient.dir/client/main.cpp.o.requires

CMakeFiles/mergesortClient.dir/client/main.cpp.o.provides: CMakeFiles/mergesortClient.dir/client/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/mergesortClient.dir/build.make CMakeFiles/mergesortClient.dir/client/main.cpp.o.provides.build
.PHONY : CMakeFiles/mergesortClient.dir/client/main.cpp.o.provides

CMakeFiles/mergesortClient.dir/client/main.cpp.o.provides.build: CMakeFiles/mergesortClient.dir/client/main.cpp.o


# Object files for target mergesortClient
mergesortClient_OBJECTS = \
"CMakeFiles/mergesortClient.dir/client/main.cpp.o"

# External object files for target mergesortClient
mergesortClient_EXTERNAL_OBJECTS =

mergesortClient: CMakeFiles/mergesortClient.dir/client/main.cpp.o
mergesortClient: CMakeFiles/mergesortClient.dir/build.make
mergesortClient: CMakeFiles/mergesortClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/suoiccc/development/Algorithm/algorithms_toy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mergesortClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mergesortClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mergesortClient.dir/build: mergesortClient

.PHONY : CMakeFiles/mergesortClient.dir/build

CMakeFiles/mergesortClient.dir/requires: CMakeFiles/mergesortClient.dir/client/main.cpp.o.requires

.PHONY : CMakeFiles/mergesortClient.dir/requires

CMakeFiles/mergesortClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mergesortClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mergesortClient.dir/clean

CMakeFiles/mergesortClient.dir/depend:
	cd /Users/suoiccc/development/Algorithm/algorithms_toy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/suoiccc/development/Algorithm/algorithms_toy /Users/suoiccc/development/Algorithm/algorithms_toy /Users/suoiccc/development/Algorithm/algorithms_toy/cmake-build-debug /Users/suoiccc/development/Algorithm/algorithms_toy/cmake-build-debug /Users/suoiccc/development/Algorithm/algorithms_toy/cmake-build-debug/CMakeFiles/mergesortClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mergesortClient.dir/depend

