# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LeetCode_56_Merge_Intervals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LeetCode_56_Merge_Intervals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LeetCode_56_Merge_Intervals.dir/flags.make

CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.o: CMakeFiles/LeetCode_56_Merge_Intervals.dir/flags.make
CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.o -c /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/main.cpp

CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/main.cpp > CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.i

CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/main.cpp -o CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.s

# Object files for target LeetCode_56_Merge_Intervals
LeetCode_56_Merge_Intervals_OBJECTS = \
"CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.o"

# External object files for target LeetCode_56_Merge_Intervals
LeetCode_56_Merge_Intervals_EXTERNAL_OBJECTS =

LeetCode_56_Merge_Intervals: CMakeFiles/LeetCode_56_Merge_Intervals.dir/main.cpp.o
LeetCode_56_Merge_Intervals: CMakeFiles/LeetCode_56_Merge_Intervals.dir/build.make
LeetCode_56_Merge_Intervals: CMakeFiles/LeetCode_56_Merge_Intervals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LeetCode_56_Merge_Intervals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LeetCode_56_Merge_Intervals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LeetCode_56_Merge_Intervals.dir/build: LeetCode_56_Merge_Intervals

.PHONY : CMakeFiles/LeetCode_56_Merge_Intervals.dir/build

CMakeFiles/LeetCode_56_Merge_Intervals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LeetCode_56_Merge_Intervals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LeetCode_56_Merge_Intervals.dir/clean

CMakeFiles/LeetCode_56_Merge_Intervals.dir/depend:
	cd /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/cmake-build-debug /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/cmake-build-debug /Users/kayleyang/CLionProjects/Algorithm_problems/LeetCode-56-Merge-Intervals/cmake-build-debug/CMakeFiles/LeetCode_56_Merge_Intervals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LeetCode_56_Merge_Intervals.dir/depend

