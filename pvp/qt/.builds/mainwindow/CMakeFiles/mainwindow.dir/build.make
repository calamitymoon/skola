# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/d/Desktop/skola/pvp/qt/mainwindow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/d/Desktop/skola/pvp/qt/.builds/mainwindow

# Include any dependencies generated for this target.
include CMakeFiles/mainwindow.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mainwindow.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mainwindow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainwindow.dir/flags.make

mainwindow_autogen/timestamp: /usr/lib/qt6/libexec/moc
mainwindow_autogen/timestamp: /usr/lib/qt6/libexec/uic
mainwindow_autogen/timestamp: CMakeFiles/mainwindow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target mainwindow"
	/usr/bin/cmake -E cmake_autogen /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles/mainwindow_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/mainwindow_autogen/timestamp

mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /home/d/Desktop/skola/pvp/qt/mainwindow/icons.qrc
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: CMakeFiles/mainwindow_autogen.dir/AutoRcc_icons_EWIEGA46WW_Info.json
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /home/d/Desktop/skola/pvp/qt/mainwindow/icons/new.png
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /home/d/Desktop/skola/pvp/qt/mainwindow/icons/save.png
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /home/d/Desktop/skola/pvp/qt/mainwindow/icons/open.png
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /home/d/Desktop/skola/pvp/qt/mainwindow/icons/eclipse.png
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /home/d/Desktop/skola/pvp/qt/mainwindow/icons/line.png
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /home/d/Desktop/skola/pvp/qt/mainwindow/icons/close.png
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /home/d/Desktop/skola/pvp/qt/mainwindow/icons/rectangle.png
mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp: /usr/lib/qt6/libexec/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic RCC for icons.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles/mainwindow_autogen.dir/AutoRcc_icons_EWIEGA46WW_Info.json Debug

CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o: CMakeFiles/mainwindow.dir/flags.make
CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o: mainwindow_autogen/mocs_compilation.cpp
CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o: CMakeFiles/mainwindow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o -MF CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o -c /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/mainwindow_autogen/mocs_compilation.cpp

CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/mainwindow_autogen/mocs_compilation.cpp > CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.i

CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/mainwindow_autogen/mocs_compilation.cpp -o CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.s

CMakeFiles/mainwindow.dir/main.cpp.o: CMakeFiles/mainwindow.dir/flags.make
CMakeFiles/mainwindow.dir/main.cpp.o: /home/d/Desktop/skola/pvp/qt/mainwindow/main.cpp
CMakeFiles/mainwindow.dir/main.cpp.o: CMakeFiles/mainwindow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mainwindow.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainwindow.dir/main.cpp.o -MF CMakeFiles/mainwindow.dir/main.cpp.o.d -o CMakeFiles/mainwindow.dir/main.cpp.o -c /home/d/Desktop/skola/pvp/qt/mainwindow/main.cpp

CMakeFiles/mainwindow.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mainwindow.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/d/Desktop/skola/pvp/qt/mainwindow/main.cpp > CMakeFiles/mainwindow.dir/main.cpp.i

CMakeFiles/mainwindow.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mainwindow.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/d/Desktop/skola/pvp/qt/mainwindow/main.cpp -o CMakeFiles/mainwindow.dir/main.cpp.s

CMakeFiles/mainwindow.dir/mainwindow.cpp.o: CMakeFiles/mainwindow.dir/flags.make
CMakeFiles/mainwindow.dir/mainwindow.cpp.o: /home/d/Desktop/skola/pvp/qt/mainwindow/mainwindow.cpp
CMakeFiles/mainwindow.dir/mainwindow.cpp.o: CMakeFiles/mainwindow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mainwindow.dir/mainwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainwindow.dir/mainwindow.cpp.o -MF CMakeFiles/mainwindow.dir/mainwindow.cpp.o.d -o CMakeFiles/mainwindow.dir/mainwindow.cpp.o -c /home/d/Desktop/skola/pvp/qt/mainwindow/mainwindow.cpp

CMakeFiles/mainwindow.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mainwindow.dir/mainwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/d/Desktop/skola/pvp/qt/mainwindow/mainwindow.cpp > CMakeFiles/mainwindow.dir/mainwindow.cpp.i

CMakeFiles/mainwindow.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mainwindow.dir/mainwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/d/Desktop/skola/pvp/qt/mainwindow/mainwindow.cpp -o CMakeFiles/mainwindow.dir/mainwindow.cpp.s

CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o: CMakeFiles/mainwindow.dir/flags.make
CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o: mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp
CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o: CMakeFiles/mainwindow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o -MF CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o.d -o CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o -c /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp

CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp > CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.i

CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp -o CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.s

# Object files for target mainwindow
mainwindow_OBJECTS = \
"CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/mainwindow.dir/main.cpp.o" \
"CMakeFiles/mainwindow.dir/mainwindow.cpp.o" \
"CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o"

# External object files for target mainwindow
mainwindow_EXTERNAL_OBJECTS =

mainwindow: CMakeFiles/mainwindow.dir/mainwindow_autogen/mocs_compilation.cpp.o
mainwindow: CMakeFiles/mainwindow.dir/main.cpp.o
mainwindow: CMakeFiles/mainwindow.dir/mainwindow.cpp.o
mainwindow: CMakeFiles/mainwindow.dir/mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp.o
mainwindow: CMakeFiles/mainwindow.dir/build.make
mainwindow: /usr/lib/x86_64-linux-gnu/libQt6Widgets.so.6.4.2
mainwindow: /usr/lib/x86_64-linux-gnu/libQt6Gui.so.6.4.2
mainwindow: /usr/lib/x86_64-linux-gnu/libQt6Core.so.6.4.2
mainwindow: /usr/lib/x86_64-linux-gnu/libGLX.so
mainwindow: /usr/lib/x86_64-linux-gnu/libOpenGL.so
mainwindow: CMakeFiles/mainwindow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable mainwindow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainwindow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainwindow.dir/build: mainwindow
.PHONY : CMakeFiles/mainwindow.dir/build

CMakeFiles/mainwindow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainwindow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainwindow.dir/clean

CMakeFiles/mainwindow.dir/depend: mainwindow_autogen/EWIEGA46WW/qrc_icons.cpp
CMakeFiles/mainwindow.dir/depend: mainwindow_autogen/timestamp
	cd /home/d/Desktop/skola/pvp/qt/.builds/mainwindow && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/d/Desktop/skola/pvp/qt/mainwindow /home/d/Desktop/skola/pvp/qt/mainwindow /home/d/Desktop/skola/pvp/qt/.builds/mainwindow /home/d/Desktop/skola/pvp/qt/.builds/mainwindow /home/d/Desktop/skola/pvp/qt/.builds/mainwindow/CMakeFiles/mainwindow.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mainwindow.dir/depend
