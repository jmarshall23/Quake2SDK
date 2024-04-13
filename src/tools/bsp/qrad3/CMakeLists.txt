cmake_minimum_required(VERSION 3.14)
project(qrad3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(../../common)

# Source files
set(SOURCE_FILES
    patches.c
    lightmap.c
    qrad3.c
    trace.c
    ../../common/threads.c
    ../../common/cmdlib.c
    ../../common/mathlib.c
    ../../common/polylib.c
    ../../common/scriplib.c
    ../../common/bspfile.c
    ../../common/lbmlib.c
)

# Define the executable
add_executable(qrad3 ${SOURCE_FILES})

# Linking settings
target_link_libraries(qrad3 wsock32 opengl32 glu32 kernel32 user32 gdi32 winspool comdlg32 advapi32 shell32 ole32 oleaut32 uuid odbc32 odbccp32)

# Definitions
target_compile_definitions(qrad3 PRIVATE -DWIN32 -D_CONSOLE -DNDEBUG)

# Set the output directory for the DLL and import library
set_target_properties(qrad3 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../../../tools/
)