# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Study\Code\Database\Database

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Study\Code\Database\Database\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Database.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Database.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Database.dir/flags.make

CMakeFiles/Database.dir/main.cpp.obj: CMakeFiles/Database.dir/flags.make
CMakeFiles/Database.dir/main.cpp.obj: CMakeFiles/Database.dir/includes_CXX.rsp
CMakeFiles/Database.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\Code\Database\Database\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Database.dir/main.cpp.obj"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Database.dir\main.cpp.obj -c D:\Study\Code\Database\Database\main.cpp

CMakeFiles/Database.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Database.dir/main.cpp.i"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\Code\Database\Database\main.cpp > CMakeFiles\Database.dir\main.cpp.i

CMakeFiles/Database.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Database.dir/main.cpp.s"
	"D:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Study\Code\Database\Database\main.cpp -o CMakeFiles\Database.dir\main.cpp.s

# Object files for target Database
Database_OBJECTS = \
"CMakeFiles/Database.dir/main.cpp.obj"

# External object files for target Database
Database_EXTERNAL_OBJECTS =

Database.exe: CMakeFiles/Database.dir/main.cpp.obj
Database.exe: CMakeFiles/Database.dir/build.make
Database.exe: ast/libast.a
Database.exe: parser/libparser.a
Database.exe: inputBuffer/libinputBuffer.a
Database.exe: Storage/libstorage.a
Database.exe: ast/libast.a
Database.exe: parser/libparser.a
Database.exe: CMakeFiles/Database.dir/linklibs.rsp
Database.exe: CMakeFiles/Database.dir/objects1.rsp
Database.exe: CMakeFiles/Database.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Study\Code\Database\Database\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Database.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Database.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Database.dir/build: Database.exe
.PHONY : CMakeFiles/Database.dir/build

CMakeFiles/Database.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Database.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Database.dir/clean

CMakeFiles/Database.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Study\Code\Database\Database D:\Study\Code\Database\Database D:\Study\Code\Database\Database\cmake-build-debug D:\Study\Code\Database\Database\cmake-build-debug D:\Study\Code\Database\Database\cmake-build-debug\CMakeFiles\Database.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Database.dir/depend

