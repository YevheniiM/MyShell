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
CMAKE_SOURCE_DIR = /mnt/d/Projects/Third_year/OS/MyShell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Projects/Third_year/OS/MyShell/build

# Include any dependencies generated for this target.
include CMakeFiles/mycat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mycat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mycat.dir/flags.make

CMakeFiles/mycat.dir/mycat/mycat.cpp.o: CMakeFiles/mycat.dir/flags.make
CMakeFiles/mycat.dir/mycat/mycat.cpp.o: ../mycat/mycat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/Third_year/OS/MyShell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mycat.dir/mycat/mycat.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mycat.dir/mycat/mycat.cpp.o -c /mnt/d/Projects/Third_year/OS/MyShell/mycat/mycat.cpp

CMakeFiles/mycat.dir/mycat/mycat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mycat.dir/mycat/mycat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/Third_year/OS/MyShell/mycat/mycat.cpp > CMakeFiles/mycat.dir/mycat/mycat.cpp.i

CMakeFiles/mycat.dir/mycat/mycat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mycat.dir/mycat/mycat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/Third_year/OS/MyShell/mycat/mycat.cpp -o CMakeFiles/mycat.dir/mycat/mycat.cpp.s

CMakeFiles/mycat.dir/mycat/mycat.cpp.o.requires:

.PHONY : CMakeFiles/mycat.dir/mycat/mycat.cpp.o.requires

CMakeFiles/mycat.dir/mycat/mycat.cpp.o.provides: CMakeFiles/mycat.dir/mycat/mycat.cpp.o.requires
	$(MAKE) -f CMakeFiles/mycat.dir/build.make CMakeFiles/mycat.dir/mycat/mycat.cpp.o.provides.build
.PHONY : CMakeFiles/mycat.dir/mycat/mycat.cpp.o.provides

CMakeFiles/mycat.dir/mycat/mycat.cpp.o.provides.build: CMakeFiles/mycat.dir/mycat/mycat.cpp.o


CMakeFiles/mycat.dir/mycat/low_level.cpp.o: CMakeFiles/mycat.dir/flags.make
CMakeFiles/mycat.dir/mycat/low_level.cpp.o: ../mycat/low_level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/Third_year/OS/MyShell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mycat.dir/mycat/low_level.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mycat.dir/mycat/low_level.cpp.o -c /mnt/d/Projects/Third_year/OS/MyShell/mycat/low_level.cpp

CMakeFiles/mycat.dir/mycat/low_level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mycat.dir/mycat/low_level.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/Third_year/OS/MyShell/mycat/low_level.cpp > CMakeFiles/mycat.dir/mycat/low_level.cpp.i

CMakeFiles/mycat.dir/mycat/low_level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mycat.dir/mycat/low_level.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/Third_year/OS/MyShell/mycat/low_level.cpp -o CMakeFiles/mycat.dir/mycat/low_level.cpp.s

CMakeFiles/mycat.dir/mycat/low_level.cpp.o.requires:

.PHONY : CMakeFiles/mycat.dir/mycat/low_level.cpp.o.requires

CMakeFiles/mycat.dir/mycat/low_level.cpp.o.provides: CMakeFiles/mycat.dir/mycat/low_level.cpp.o.requires
	$(MAKE) -f CMakeFiles/mycat.dir/build.make CMakeFiles/mycat.dir/mycat/low_level.cpp.o.provides.build
.PHONY : CMakeFiles/mycat.dir/mycat/low_level.cpp.o.provides

CMakeFiles/mycat.dir/mycat/low_level.cpp.o.provides.build: CMakeFiles/mycat.dir/mycat/low_level.cpp.o


CMakeFiles/mycat.dir/mycat/high_level.cpp.o: CMakeFiles/mycat.dir/flags.make
CMakeFiles/mycat.dir/mycat/high_level.cpp.o: ../mycat/high_level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/Third_year/OS/MyShell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mycat.dir/mycat/high_level.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mycat.dir/mycat/high_level.cpp.o -c /mnt/d/Projects/Third_year/OS/MyShell/mycat/high_level.cpp

CMakeFiles/mycat.dir/mycat/high_level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mycat.dir/mycat/high_level.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/Third_year/OS/MyShell/mycat/high_level.cpp > CMakeFiles/mycat.dir/mycat/high_level.cpp.i

CMakeFiles/mycat.dir/mycat/high_level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mycat.dir/mycat/high_level.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/Third_year/OS/MyShell/mycat/high_level.cpp -o CMakeFiles/mycat.dir/mycat/high_level.cpp.s

CMakeFiles/mycat.dir/mycat/high_level.cpp.o.requires:

.PHONY : CMakeFiles/mycat.dir/mycat/high_level.cpp.o.requires

CMakeFiles/mycat.dir/mycat/high_level.cpp.o.provides: CMakeFiles/mycat.dir/mycat/high_level.cpp.o.requires
	$(MAKE) -f CMakeFiles/mycat.dir/build.make CMakeFiles/mycat.dir/mycat/high_level.cpp.o.provides.build
.PHONY : CMakeFiles/mycat.dir/mycat/high_level.cpp.o.provides

CMakeFiles/mycat.dir/mycat/high_level.cpp.o.provides.build: CMakeFiles/mycat.dir/mycat/high_level.cpp.o


# Object files for target mycat
mycat_OBJECTS = \
"CMakeFiles/mycat.dir/mycat/mycat.cpp.o" \
"CMakeFiles/mycat.dir/mycat/low_level.cpp.o" \
"CMakeFiles/mycat.dir/mycat/high_level.cpp.o"

# External object files for target mycat
mycat_EXTERNAL_OBJECTS =

../bin/mycat: CMakeFiles/mycat.dir/mycat/mycat.cpp.o
../bin/mycat: CMakeFiles/mycat.dir/mycat/low_level.cpp.o
../bin/mycat: CMakeFiles/mycat.dir/mycat/high_level.cpp.o
../bin/mycat: CMakeFiles/mycat.dir/build.make
../bin/mycat: CMakeFiles/mycat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Projects/Third_year/OS/MyShell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/mycat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mycat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mycat.dir/build: ../bin/mycat

.PHONY : CMakeFiles/mycat.dir/build

CMakeFiles/mycat.dir/requires: CMakeFiles/mycat.dir/mycat/mycat.cpp.o.requires
CMakeFiles/mycat.dir/requires: CMakeFiles/mycat.dir/mycat/low_level.cpp.o.requires
CMakeFiles/mycat.dir/requires: CMakeFiles/mycat.dir/mycat/high_level.cpp.o.requires

.PHONY : CMakeFiles/mycat.dir/requires

CMakeFiles/mycat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mycat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mycat.dir/clean

CMakeFiles/mycat.dir/depend:
	cd /mnt/d/Projects/Third_year/OS/MyShell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Projects/Third_year/OS/MyShell /mnt/d/Projects/Third_year/OS/MyShell /mnt/d/Projects/Third_year/OS/MyShell/build /mnt/d/Projects/Third_year/OS/MyShell/build /mnt/d/Projects/Third_year/OS/MyShell/build/CMakeFiles/mycat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mycat.dir/depend
