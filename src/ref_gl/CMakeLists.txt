cmake_minimum_required(VERSION 3.10)

# Project name
project(ref_gl)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;DebugAlpha;ReleaseAlpha")

# Source files
set(SOURCE_FILES
    gl_draw.c
    gl_image.c
    gl_light.c
    gl_mesh.c
    gl_model.c
    gl_rmain.c
    gl_rmisc.c
    gl_rsurf.c
    gl_warp.c
    ../win32/glw_imp.c
    ../game/q_shared.c
    ../win32/q_shwin.c
    ../win32/qgl_win.c
)

# Define the DLL target
add_library(ref_gl SHARED ${SOURCE_FILES})

# Link with necessary libraries
target_link_libraries(ref_gl
    opengl32
    glu32
    winmm
    gdi32
    user32
)

# Including the .def file for symbol exports
target_link_options(ref_gl PRIVATE 
   /DEF:${CMAKE_CURRENT_SOURCE_DIR}/ref_gl.def
)

# Compiler options and definitions for different configurations
target_compile_definitions(ref_gl PRIVATE
    $<$<CONFIG:Debug>:WIN32;_DEBUG;_WINDOWS>
    $<$<CONFIG:Release>:WIN32;NDEBUG;_WINDOWS>
)

target_compile_options(ref_gl PRIVATE
    $<$<CONFIG:Debug>:/MTd;/W3;/Gm;/GX;/Zi;/Od>
    $<$<CONFIG:Release>:/MT;/W3;/GX;/O2>
)

# Set the output directory for the DLL and import library
set_target_properties(ref_gl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../../../
)
