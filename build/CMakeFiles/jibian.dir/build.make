# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/share/cmake-3.22.1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /usr/share/cmake-3.22.1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ww/opencv/biaoding

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ww/opencv/biaoding/build

# Include any dependencies generated for this target.
include CMakeFiles/jibian.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/jibian.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/jibian.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jibian.dir/flags.make

CMakeFiles/jibian.dir/main.cpp.o: CMakeFiles/jibian.dir/flags.make
CMakeFiles/jibian.dir/main.cpp.o: ../main.cpp
CMakeFiles/jibian.dir/main.cpp.o: CMakeFiles/jibian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ww/opencv/biaoding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/jibian.dir/main.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/jibian.dir/main.cpp.o -MF CMakeFiles/jibian.dir/main.cpp.o.d -o CMakeFiles/jibian.dir/main.cpp.o -c /home/ww/opencv/biaoding/main.cpp

CMakeFiles/jibian.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jibian.dir/main.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ww/opencv/biaoding/main.cpp > CMakeFiles/jibian.dir/main.cpp.i

CMakeFiles/jibian.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jibian.dir/main.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ww/opencv/biaoding/main.cpp -o CMakeFiles/jibian.dir/main.cpp.s

# Object files for target jibian
jibian_OBJECTS = \
"CMakeFiles/jibian.dir/main.cpp.o"

# External object files for target jibian
jibian_EXTERNAL_OBJECTS =

jibian: CMakeFiles/jibian.dir/main.cpp.o
jibian: CMakeFiles/jibian.dir/build.make
jibian: /usr/local/lib/libopencv_gapi.so.4.5.5
jibian: /usr/local/lib/libopencv_highgui.so.4.5.5
jibian: /usr/local/lib/libopencv_ml.so.4.5.5
jibian: /usr/local/lib/libopencv_objdetect.so.4.5.5
jibian: /usr/local/lib/libopencv_photo.so.4.5.5
jibian: /usr/local/lib/libopencv_stitching.so.4.5.5
jibian: /usr/local/lib/libopencv_video.so.4.5.5
jibian: /usr/local/lib/libopencv_videoio.so.4.5.5
jibian: /usr/local/lib/libopencv_imgcodecs.so.4.5.5
jibian: /usr/local/lib/libopencv_dnn.so.4.5.5
jibian: /usr/local/lib/libopencv_calib3d.so.4.5.5
jibian: /usr/local/lib/libopencv_features2d.so.4.5.5
jibian: /usr/local/lib/libopencv_flann.so.4.5.5
jibian: /usr/local/lib/libopencv_imgproc.so.4.5.5
jibian: /usr/local/lib/libopencv_core.so.4.5.5
jibian: CMakeFiles/jibian.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ww/opencv/biaoding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable jibian"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jibian.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jibian.dir/build: jibian
.PHONY : CMakeFiles/jibian.dir/build

CMakeFiles/jibian.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jibian.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jibian.dir/clean

CMakeFiles/jibian.dir/depend:
	cd /home/ww/opencv/biaoding/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ww/opencv/biaoding /home/ww/opencv/biaoding /home/ww/opencv/biaoding/build /home/ww/opencv/biaoding/build /home/ww/opencv/biaoding/build/CMakeFiles/jibian.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jibian.dir/depend
