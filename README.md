# Unofficial Quake 2 SDK

This depot is a base for people to develop Quake 2 content. The code is untouched from the original GPL release, except `gamex86.dll` is now just `game.dll`. Having everyone in one spot is a good starting point for making stuff.

## Features

- **CMake Integration**: Includes CMake files that can be opened directly from Visual Studio 2022. These files are set up for compiling the game, engine, editor (`qe4`, the original editor), `bsp`, `rad`, and `vis`. The "Build All" option builds everything.
- **Quake 2 Demo**: All files in this section are property of id Software and are only included to get the game up and running. All content will have to be created by you.

## How to use

Open visual studio 2022, open cmake and cmakelists.txt in the src folder, then build all. Make sure you edit the paths in tools/scripts/quake.qe4 so the editor runs. 
