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
CMAKE_SOURCE_DIR = /Users/JohnJD/extra/GitHub/hiho

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/JohnJD/extra/GitHub/hiho/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/hiho.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hiho.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hiho.dir/flags.make

CMakeFiles/hiho.dir/1109.cc.o: CMakeFiles/hiho.dir/flags.make
CMakeFiles/hiho.dir/1109.cc.o: ../1109.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/JohnJD/extra/GitHub/hiho/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hiho.dir/1109.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hiho.dir/1109.cc.o -c /Users/JohnJD/extra/GitHub/hiho/1109.cc

CMakeFiles/hiho.dir/1109.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hiho.dir/1109.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/JohnJD/extra/GitHub/hiho/1109.cc > CMakeFiles/hiho.dir/1109.cc.i

CMakeFiles/hiho.dir/1109.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hiho.dir/1109.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/JohnJD/extra/GitHub/hiho/1109.cc -o CMakeFiles/hiho.dir/1109.cc.s

CMakeFiles/hiho.dir/1109.cc.o.requires:

.PHONY : CMakeFiles/hiho.dir/1109.cc.o.requires

CMakeFiles/hiho.dir/1109.cc.o.provides: CMakeFiles/hiho.dir/1109.cc.o.requires
	$(MAKE) -f CMakeFiles/hiho.dir/build.make CMakeFiles/hiho.dir/1109.cc.o.provides.build
.PHONY : CMakeFiles/hiho.dir/1109.cc.o.provides

CMakeFiles/hiho.dir/1109.cc.o.provides.build: CMakeFiles/hiho.dir/1109.cc.o


# Object files for target hiho
hiho_OBJECTS = \
"CMakeFiles/hiho.dir/1109.cc.o"

# External object files for target hiho
hiho_EXTERNAL_OBJECTS =

hiho: CMakeFiles/hiho.dir/1109.cc.o
hiho: CMakeFiles/hiho.dir/build.make
hiho: CMakeFiles/hiho.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/JohnJD/extra/GitHub/hiho/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hiho"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hiho.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hiho.dir/build: hiho

.PHONY : CMakeFiles/hiho.dir/build

CMakeFiles/hiho.dir/requires: CMakeFiles/hiho.dir/1109.cc.o.requires

.PHONY : CMakeFiles/hiho.dir/requires

CMakeFiles/hiho.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hiho.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hiho.dir/clean

CMakeFiles/hiho.dir/depend:
	cd /Users/JohnJD/extra/GitHub/hiho/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/JohnJD/extra/GitHub/hiho /Users/JohnJD/extra/GitHub/hiho /Users/JohnJD/extra/GitHub/hiho/cmake-build-release /Users/JohnJD/extra/GitHub/hiho/cmake-build-release /Users/JohnJD/extra/GitHub/hiho/cmake-build-release/CMakeFiles/hiho.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hiho.dir/depend

