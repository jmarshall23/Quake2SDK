cmake_minimum_required(VERSION 3.14)
project(quake2 VERSION 1.0 DESCRIPTION "Quake II Game" LANGUAGES C)

add_subdirectory(game)
add_subdirectory(ref_gl)
add_subdirectory(tools/qe4)
add_subdirectory(tools/bsp/qbsp3)
add_subdirectory(tools/bsp/qrad3)
add_subdirectory(tools/bsp/qvis3)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/client
    ${PROJECT_SOURCE_DIR}/game
    ${PROJECT_SOURCE_DIR}/qcommon
    ${PROJECT_SOURCE_DIR}/server
    ${PROJECT_SOURCE_DIR}/win32
)

# Source files list
set(SOURCE_FILES
    client/cl_cin.c
    client/cl_ents.c
    client/cl_fx.c
    client/cl_input.c
    client/cl_inv.c
    client/cl_main.c
    client/cl_newfx.c
    client/cl_parse.c
    client/cl_pred.c
    client/cl_scrn.c
    client/cl_tent.c
    client/cl_view.c
    client/console.c
    client/keys.c
    client/menu.c
    client/qmenu.c
    client/snd_dma.c
    client/snd_mem.c
    client/snd_mix.c
    client/x86.c
    game/m_flash.c
    game/q_shared.c
    qcommon/cmd.c
    qcommon/cmodel.c
    qcommon/common.c
    qcommon/crc.c
    qcommon/cvar.c
    qcommon/files.c
    qcommon/md4.c
    qcommon/net_chan.c
    qcommon/pmove.c
    server/sv_ccmds.c
    server/sv_ents.c
    server/sv_game.c
    server/sv_init.c
    server/sv_main.c
    server/sv_send.c
    server/sv_user.c
    server/sv_world.c
    win32/cd_win.c
    win32/conproc.c
    win32/in_win.c
    win32/net_wins.c
    win32/q_shwin.c
    win32/snd_win.c
    win32/sys_win.c
    win32/vid_dll.c
    win32/vid_menu.c
)

# Resource Files
set(RESOURCE_FILES
    win32/q2.rc
)

# Define the executable target
add_executable(quake2 WIN32 ${SOURCE_FILES} ${RESOURCE_FILES})

# Specify libraries to link
target_link_libraries(quake2 wsock32 winmm)

# Compiler options and definitions
if(MSVC)
    target_compile_definitions(quake2 PRIVATE "_WINDOWS" "WIN32")
    if(CMAKE_BUILD_TYPE MATCHES Debug)
        target_compile_definitions(quake2 PRIVATE "_DEBUG")
        target_compile_options(quake2 PRIVATE /W3 /Zi /Od /Gm)
    else()
        target_compile_definitions(quake2 PRIVATE "NDEBUG")
        target_compile_options(quake2 PRIVATE /W3 /O2)
    endif()
endif()

set_target_properties(quake2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../../../
)