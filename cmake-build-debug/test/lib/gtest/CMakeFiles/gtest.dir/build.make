# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/bmolnar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/bmolnar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/bmolnar/Data/ocs_1/measurmentunits

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug

# Include any dependencies generated for this target.
include test/lib/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include test/lib/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include test/lib/gtest/CMakeFiles/gtest.dir/flags.make

test/lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: test/lib/gtest/CMakeFiles/gtest.dir/flags.make
test/lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../test/lib/gtest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/test/lib/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /media/bmolnar/Data/ocs_1/measurmentunits/test/lib/gtest/src/gtest-all.cc

test/lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/test/lib/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/bmolnar/Data/ocs_1/measurmentunits/test/lib/gtest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

test/lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/test/lib/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/bmolnar/Data/ocs_1/measurmentunits/test/lib/gtest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

../bin/libgtest.a: test/lib/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
../bin/libgtest.a: test/lib/gtest/CMakeFiles/gtest.dir/build.make
../bin/libgtest.a: test/lib/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../bin/libgtest.a"
	cd /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/test/lib/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/test/lib/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/lib/gtest/CMakeFiles/gtest.dir/build: ../bin/libgtest.a

.PHONY : test/lib/gtest/CMakeFiles/gtest.dir/build

test/lib/gtest/CMakeFiles/gtest.dir/clean:
	cd /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/test/lib/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : test/lib/gtest/CMakeFiles/gtest.dir/clean

test/lib/gtest/CMakeFiles/gtest.dir/depend:
	cd /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/bmolnar/Data/ocs_1/measurmentunits /media/bmolnar/Data/ocs_1/measurmentunits/test/lib/gtest /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/test/lib/gtest /media/bmolnar/Data/ocs_1/measurmentunits/cmake-build-debug/test/lib/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/lib/gtest/CMakeFiles/gtest.dir/depend

