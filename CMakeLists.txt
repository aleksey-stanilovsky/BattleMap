cmake_minimum_required(VERSION 3.23)
project(BattleMap)

set(CMAKE_CXX_STANDARD 20)

add_executable(BattleMap
        main.cpp
        units/interface/unit.h
        units/interface/unit.cpp
        units/creator.h
        units/creator.cpp
        units/warrior.h
        units/warrior.cpp
        units/archer.cpp
        units/archer.h
        common/constants.h
        common/logger.h
        common/logger.cpp
        game/game.h
        game/game.cpp units/interface/attacker.h units/interface/attacker.cpp units/interface/meleeAttacker.h units/interface/meleeAttacker.cpp units/interface/rangeAttacker.cpp units/interface/rangeAttacker.h)
