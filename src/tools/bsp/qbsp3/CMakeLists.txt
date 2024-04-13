cmake_minimum_required(VERSION 3.14)
project(qbsp3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(../../common)

# Source files
set(SOURCE_FILES
    writebsp.c
    brushbsp.c
    csg.c
    faces.c
    gldraw.c
    glfile.c
    leakfile.c
    map.c
    portals.c
    prtfile.c
    qbsp3.c
    textures.c
    tree.c
    ../../common/threads.c
    ../../common/cmdlib.c
    ../../common/mathlib.c
    ../../common/polylib.c
    ../../common/scriplib.c
    ../../common/bspfile.c
)

# Define the executable
add_executable(qbsp3 ${SOURCE_FILES})

# Linking settings
target_link_libraries(qbsp3 wsock32 opengl32 glu32 kernel32 user32 gdi32 winspool comdlg32 advapi32 shell32 ole32 oleaut32 uuid odbc32 odbccp32)

# Definitions
target_compile_definitions(qbsp3 PRIVATE -DWIN32 -D_CONSOLE -DNDEBUG)

# Set the output directory for the DLL and import library
set_target_properties(qbsp3 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../../../tools/
)