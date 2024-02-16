# BattleMap

## Description
BattleMap is a project that is an interactive map for fighting in role—playing games. The project allows users to create and manage maps of battle arenas, place units on them, and visualize the course of the battle.

## Functionality
- Create and edit battle arena maps.
- Placement and management of units on the map.
- Visualization of the course of the battle and the movement of units.

## Technologies
The project was developed using the following technologies:
- C++ 20

## Running Requirements

For the application to function correctly, a `script.txt` file is necessary, which should be located in a any directory. This file is essential for defining the initial setup and actions within the BattleMap application, adhering to a specific command and argument structure for game initialization and unit management.

Please ensure that the `script.txt` file is available and you have **passed path to it as an argument** to an executable before launching the application.

### Format of `script.txt`

The file follows a command-based structure where each line represents an action to be taken within the game environment:

- **CREATE_MAP [width] [height]**: Initializes the game map with the specified dimensions. **This command can only appear once and must be at the beginning of the file**.
- **SPAWN_WARRIOR [id] [x] [y] [hp] [strength]**: Places a warrior unit on the map at the specified coordinates with the defined health and strength.
- **SPAWN_ARCHER [id] [x] [y] [hp] [strength] [range] [agility]**: Places an archer unit on the map at the specified coordinates with defined health, strength, range, and agility attributes.
- **MARCH [unit_id] [x] [y]**: Commands a unit to move to the specified coordinates.
- **WAIT [ticks]**: Pauses the execution of subsequent commands for a specified number of ticks.

### Example of `script.txt` Content

```plaintext
CREATE_MAP 30 30
SPAWN_WARRIOR 1 2 3 15 5
SPAWN_ARCHER 3 19 20 10 2 2 3
SPAWN_ARCHER 2 13 23 10 2 2 3
MARCH 1 11 21
WAIT 10
MARCH 3 14 24
WAIT 10
```

### Launching the Application with `script.txt`

To launch the application using the `script.txt` file, ensure that the file is located in [specify location]. Then, execute the following command:

```bash
./BattleMap ../scenario.txt
```

## Installation and launch
To use the project, you need to clone the repository and build the project using the following commands:

```bash
git clone https://github.com/aleksey-stanilovsky/BattleMap.git
cd BattleMap
mkdir build
cd build
cmake ../
cmake --build . --config Release
```
