# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\build

# Include any dependencies generated for this target.
include CMakeFiles/TicTacToeXtrem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TicTacToeXtrem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TicTacToeXtrem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TicTacToeXtrem.dir/flags.make

CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.obj: CMakeFiles/TicTacToeXtrem.dir/flags.make
CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.obj: C:/Users/Denni/VSCode/Cpp/TicTacToe-Extreme/src/GameManager.cpp
CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.obj: CMakeFiles/TicTacToeXtrem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.obj -MF CMakeFiles\TicTacToeXtrem.dir\src\GameManager.cpp.obj.d -o CMakeFiles\TicTacToeXtrem.dir\src\GameManager.cpp.obj -c C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\src\GameManager.cpp

CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\src\GameManager.cpp > CMakeFiles\TicTacToeXtrem.dir\src\GameManager.cpp.i

CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\src\GameManager.cpp -o CMakeFiles\TicTacToeXtrem.dir\src\GameManager.cpp.s

# Object files for target TicTacToeXtrem
TicTacToeXtrem_OBJECTS = \
"CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.obj"

# External object files for target TicTacToeXtrem
TicTacToeXtrem_EXTERNAL_OBJECTS =

libTicTacToeXtrem.a: CMakeFiles/TicTacToeXtrem.dir/src/GameManager.cpp.obj
libTicTacToeXtrem.a: CMakeFiles/TicTacToeXtrem.dir/build.make
libTicTacToeXtrem.a: CMakeFiles/TicTacToeXtrem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTicTacToeXtrem.a"
	$(CMAKE_COMMAND) -P CMakeFiles\TicTacToeXtrem.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TicTacToeXtrem.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TicTacToeXtrem.dir/build: libTicTacToeXtrem.a
.PHONY : CMakeFiles/TicTacToeXtrem.dir/build

CMakeFiles/TicTacToeXtrem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TicTacToeXtrem.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TicTacToeXtrem.dir/clean

CMakeFiles/TicTacToeXtrem.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\build C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\build C:\Users\Denni\VSCode\Cpp\TicTacToe-Extreme\build\CMakeFiles\TicTacToeXtrem.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TicTacToeXtrem.dir/depend

