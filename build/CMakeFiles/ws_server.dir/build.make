# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/kin/sandbox/WebSocketTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kin/sandbox/WebSocketTest/build

# Include any dependencies generated for this target.
include CMakeFiles/ws_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ws_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ws_server.dir/flags.make

CMakeFiles/ws_server.dir/ws_server.cpp.o: CMakeFiles/ws_server.dir/flags.make
CMakeFiles/ws_server.dir/ws_server.cpp.o: ../ws_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kin/sandbox/WebSocketTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ws_server.dir/ws_server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ws_server.dir/ws_server.cpp.o -c /home/kin/sandbox/WebSocketTest/ws_server.cpp

CMakeFiles/ws_server.dir/ws_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ws_server.dir/ws_server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kin/sandbox/WebSocketTest/ws_server.cpp > CMakeFiles/ws_server.dir/ws_server.cpp.i

CMakeFiles/ws_server.dir/ws_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ws_server.dir/ws_server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kin/sandbox/WebSocketTest/ws_server.cpp -o CMakeFiles/ws_server.dir/ws_server.cpp.s

CMakeFiles/ws_server.dir/ws_server.cpp.o.requires:

.PHONY : CMakeFiles/ws_server.dir/ws_server.cpp.o.requires

CMakeFiles/ws_server.dir/ws_server.cpp.o.provides: CMakeFiles/ws_server.dir/ws_server.cpp.o.requires
	$(MAKE) -f CMakeFiles/ws_server.dir/build.make CMakeFiles/ws_server.dir/ws_server.cpp.o.provides.build
.PHONY : CMakeFiles/ws_server.dir/ws_server.cpp.o.provides

CMakeFiles/ws_server.dir/ws_server.cpp.o.provides.build: CMakeFiles/ws_server.dir/ws_server.cpp.o


# Object files for target ws_server
ws_server_OBJECTS = \
"CMakeFiles/ws_server.dir/ws_server.cpp.o"

# External object files for target ws_server
ws_server_EXTERNAL_OBJECTS =

bin/ws_server: CMakeFiles/ws_server.dir/ws_server.cpp.o
bin/ws_server: CMakeFiles/ws_server.dir/build.make
bin/ws_server: /usr/lib/x86_64-linux-gnu/libboost_system.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libboost_coroutine.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libboost_context.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libpthread.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libssl.so
bin/ws_server: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/ws_server: CMakeFiles/ws_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kin/sandbox/WebSocketTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/ws_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ws_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ws_server.dir/build: bin/ws_server

.PHONY : CMakeFiles/ws_server.dir/build

CMakeFiles/ws_server.dir/requires: CMakeFiles/ws_server.dir/ws_server.cpp.o.requires

.PHONY : CMakeFiles/ws_server.dir/requires

CMakeFiles/ws_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ws_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ws_server.dir/clean

CMakeFiles/ws_server.dir/depend:
	cd /home/kin/sandbox/WebSocketTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kin/sandbox/WebSocketTest /home/kin/sandbox/WebSocketTest /home/kin/sandbox/WebSocketTest/build /home/kin/sandbox/WebSocketTest/build /home/kin/sandbox/WebSocketTest/build/CMakeFiles/ws_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ws_server.dir/depend

