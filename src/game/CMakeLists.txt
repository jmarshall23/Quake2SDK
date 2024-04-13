cmake_minimum_required(VERSION 3.10)

# Set your project name
project(game)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;DebugAlpha;ReleaseAlpha")

# Include directories
include_directories(.)

# Source files
set(SOURCE_FILES
    g_ai.c
    g_chase.c
    g_cmds.c
    g_combat.c
    g_func.c
    g_items.c
    g_main.c
    g_misc.c
    g_monster.c
    g_phys.c
    g_save.c
    g_spawn.c
    g_svcmds.c
    g_target.c
    g_trigger.c
    g_turret.c
    g_utils.c
    g_weapon.c
    m_actor.c
    m_berserk.c
    m_boss2.c
    m_boss3.c
    m_boss31.c
    m_boss32.c
    m_brain.c
    m_chick.c
    m_flash.c
    m_flipper.c
    m_float.c
    m_flyer.c
    m_gladiator.c
    m_gunner.c
    m_hover.c
    m_infantry.c
    m_insane.c
    m_medic.c
    m_move.c
    m_mutant.c
    m_parasite.c
    m_soldier.c
    m_supertank.c
    m_tank.c
    p_client.c
    p_hud.c
    p_trail.c
    p_view.c
    p_weapon.c
    q_shared.c
)

# Define the library or executable target
add_library(game SHARED ${SOURCE_FILES})

# Link libraries
target_link_libraries(game
    kernel32.lib
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
    winmm.lib
)

# Including the .def file for symbol exports
target_link_options(game PRIVATE 
   /DEF:${CMAKE_CURRENT_SOURCE_DIR}/game.def
)

# Compiler options for different configurations
target_compile_definitions(game PRIVATE
    $<$<CONFIG:Debug>:WIN32;_DEBUG;_WINDOWS;BUILDING_REF_GL>
    $<$<CONFIG:Release>:WIN32;NDEBUG;_WINDOWS>
)

target_compile_options(game PRIVATE
    $<$<CONFIG:Debug>:/MTd;/W3;/Gm;/GX;/Zi;/Od>
    $<$<CONFIG:Release>:/MT;/W3;/GX;/O2>
)

# Set the output directory for the DLL and import library
set_target_properties(game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../../../
)
