# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/wawrze/clion-2019.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wawrze/clion-2019.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wawrze/C_projects/shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wawrze/C_projects/shell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/commands.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/commands.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/commands.dir/flags.make

CMakeFiles/commands.dir/commands.c.o: CMakeFiles/commands.dir/flags.make
CMakeFiles/commands.dir/commands.c.o: ../commands.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wawrze/C_projects/shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/commands.dir/commands.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/commands.dir/commands.c.o   -c /home/wawrze/C_projects/shell/commands.c

CMakeFiles/commands.dir/commands.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/commands.dir/commands.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wawrze/C_projects/shell/commands.c > CMakeFiles/commands.dir/commands.c.i

CMakeFiles/commands.dir/commands.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/commands.dir/commands.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wawrze/C_projects/shell/commands.c -o CMakeFiles/commands.dir/commands.c.s

# Object files for target commands
commands_OBJECTS = \
"CMakeFiles/commands.dir/commands.c.o"

# External object files for target commands
commands_EXTERNAL_OBJECTS =

commands: CMakeFiles/commands.dir/commands.c.o
commands: CMakeFiles/commands.dir/build.make
commands: CMakeFiles/commands.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wawrze/C_projects/shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable commands"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/commands.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/commands.dir/build: commands

.PHONY : CMakeFiles/commands.dir/build

CMakeFiles/commands.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/commands.dir/cmake_clean.cmake
.PHONY : CMakeFiles/commands.dir/clean

CMakeFiles/commands.dir/depend:
	cd /home/wawrze/C_projects/shell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wawrze/C_projects/shell /home/wawrze/C_projects/shell /home/wawrze/C_projects/shell/cmake-build-debug /home/wawrze/C_projects/shell/cmake-build-debug /home/wawrze/C_projects/shell/cmake-build-debug/CMakeFiles/commands.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/commands.dir/depend

