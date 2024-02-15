//
// Created by alst on 14.02.24.
//

#ifndef BATTLEMAP_LOGGER_H
#define BATTLEMAP_LOGGER_H

#include "../units/creator.h"
namespace Game{
    class Logger {
    public:
        static void logInfo(const std::string &str);
        static void logError(const std::string &str);

        static void mapCreated(arg_t width, arg_t height);
        static void unitSpawned(id_t id, UNIT_TYPE type, coordinate_t &coord);
        static void marchStarted(id_t id, const coordinate_t &from, const coordinate_t &to);
        static void marchFinished(id_t id, const coordinate_t &point);
        static void receivedDamage(id_t whoId, power_t damage, id_t fromId, hp_t remainingHp);
        static void unitDied(id_t id);
    };
}

#endif //BATTLEMAP_LOGGER_H
