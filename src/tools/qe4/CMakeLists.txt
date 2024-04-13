cmake_minimum_required(VERSION 3.10)
project(QE4 VERSION 1.0 DESCRIPTION "QE4 Editor" LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Optionally, define configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# Source files
set(SOURCE_FILES
    brush.c
    camera.c
    cmdlib.c
    csg.c
    drag.c
    eclass.c
    entity.c
    lbmlib.c
    map.c
    mathlib.c
    mru.c
    parse.c
    points.c
    qe3.c
    select.c
    textures.c
    vertsel.c
    win_cam.c
    win_dlg.c
    win_ent.c
    win_main.c
    win_qe3.c
    win_xy.c
    win_z.c
    xy.c
    z.c
    win_qe3.rc
)

# Define the executable
add_executable(QE4 WIN32 ${SOURCE_FILES})

# Define libraries
target_link_libraries(QE4 PRIVATE
    opengl32.lib
    glu32.lib
    Comctl32.lib
    user32.lib
    gdi32.lib
    winspool.lib
    comdlg32.lib
    advapi32.lib
    shell32.lib
    ole32.lib
    oleaut32.lib
    uuid.lib
    odbc32.lib
    odbccp32.lib
)

# Set preprocessor definitions
target_compile_definitions(QE4 PRIVATE
    WIN32
    _WINDOWS
    NDEBUG
)

# Special handling for different configurations
target_compile_options(QE4 PRIVATE
    $<$<CONFIG:Debug>:/Zi /Od>
    $<$<CONFIG:Release>:/O2>
)

# Set the output directory for the DLL and import library
set_target_properties(QE4 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../../../tools/
)