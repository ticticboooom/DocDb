# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /cygdrive/c/Users/Kyle/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Kyle/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Kyle/source/kylebcox/DocDB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DocDB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DocDB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DocDB.dir/flags.make

CMakeFiles/DocDB.dir/main.cpp.o: CMakeFiles/DocDB.dir/flags.make
CMakeFiles/DocDB.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Kyle/source/kylebcox/DocDB/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DocDB.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DocDB.dir/main.cpp.o -c /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/main.cpp

CMakeFiles/DocDB.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DocDB.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/main.cpp > CMakeFiles/DocDB.dir/main.cpp.i

CMakeFiles/DocDB.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DocDB.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/main.cpp -o CMakeFiles/DocDB.dir/main.cpp.s

CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.o: CMakeFiles/DocDB.dir/flags.make
CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.o: ../WSDON/WSDONParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Kyle/source/kylebcox/DocDB/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.o -c /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/WSDON/WSDONParser.cpp

CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/WSDON/WSDONParser.cpp > CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.i

CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/WSDON/WSDONParser.cpp -o CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.s

# Object files for target DocDB
DocDB_OBJECTS = \
"CMakeFiles/DocDB.dir/main.cpp.o" \
"CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.o"

# External object files for target DocDB
DocDB_EXTERNAL_OBJECTS =

DocDB.exe: CMakeFiles/DocDB.dir/main.cpp.o
DocDB.exe: CMakeFiles/DocDB.dir/WSDON/WSDONParser.cpp.o
DocDB.exe: CMakeFiles/DocDB.dir/build.make
DocDB.exe: CMakeFiles/DocDB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Kyle/source/kylebcox/DocDB/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DocDB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DocDB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DocDB.dir/build: DocDB.exe

.PHONY : CMakeFiles/DocDB.dir/build

CMakeFiles/DocDB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DocDB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DocDB.dir/clean

CMakeFiles/DocDB.dir/depend:
	cd /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Kyle/source/kylebcox/DocDB /cygdrive/c/Users/Kyle/source/kylebcox/DocDB /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/cmake-build-debug /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/cmake-build-debug /cygdrive/c/Users/Kyle/source/kylebcox/DocDB/cmake-build-debug/CMakeFiles/DocDB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DocDB.dir/depend

