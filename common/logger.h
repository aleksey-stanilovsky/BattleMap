//
// Created by alst on 14.02.24.
//

#ifndef BATTLEMAP_LOGGER_H
#define BATTLEMAP_LOGGER_H

#include "../units/creator.h"

class Logger {
public:
    static void logInfo(const std::string &str);
    static void logError(const std::string &str);

    static void mapCreated(const Game::arg_t &width, const Game::arg_t &height);
    static void unitSpawned(const Game::id_t &id, const Game::UNIT_TYPE &type, const Game::coordinate_t &coord);
    static void marchStarted(const Game::id_t &id, const Game::coordinate_t &from, const Game::coordinate_t &to);
    static void marchFinished(const Game::id_t &id);
    static void receivedDamage(const Game::id_t &whoId, const Game::power_t &damage, const Game::id_t &fromId,
                               const Game::hp_t& remainingHp);
    static void unitDied(const Game::id_t &id);
};



#endif //BATTLEMAP_LOGGER_H
