# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /mnt/Devel/JetBrains/apps/apps/CLion/ch-0/211.7442.42/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /mnt/Devel/JetBrains/apps/apps/CLion/ch-0/211.7442.42/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3_kyu_battleship_field_validator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3_kyu_battleship_field_validator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3_kyu_battleship_field_validator.dir/flags.make

CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.o: CMakeFiles/3_kyu_battleship_field_validator.dir/flags.make
CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.o -c /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/main.cpp

CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/main.cpp > CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.i

CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/main.cpp -o CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.s

# Object files for target 3_kyu_battleship_field_validator
3_kyu_battleship_field_validator_OBJECTS = \
"CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.o"

# External object files for target 3_kyu_battleship_field_validator
3_kyu_battleship_field_validator_EXTERNAL_OBJECTS =

3_kyu_battleship_field_validator: CMakeFiles/3_kyu_battleship_field_validator.dir/main.cpp.o
3_kyu_battleship_field_validator: CMakeFiles/3_kyu_battleship_field_validator.dir/build.make
3_kyu_battleship_field_validator: CMakeFiles/3_kyu_battleship_field_validator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3_kyu_battleship_field_validator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3_kyu_battleship_field_validator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3_kyu_battleship_field_validator.dir/build: 3_kyu_battleship_field_validator

.PHONY : CMakeFiles/3_kyu_battleship_field_validator.dir/build

CMakeFiles/3_kyu_battleship_field_validator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3_kyu_battleship_field_validator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3_kyu_battleship_field_validator.dir/clean

CMakeFiles/3_kyu_battleship_field_validator.dir/depend:
	cd /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/cmake-build-debug /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/cmake-build-debug /mnt/Devel/GitHub/codeWars/C++/3-kyu-battleship-field-validator/cmake-build-debug/CMakeFiles/3_kyu_battleship_field_validator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3_kyu_battleship_field_validator.dir/depend

