//
// Created by alst on 14.02.24.
//
#include "../units/interface/unit.h"
#include "logger.h"

#include <sstream>
#include "iostream"
#include "../game/game.h"

namespace Game {
    void Logger::logInfo(const std::string &str) {
        std::cout << "[" << Singleton::getInstance().getTickNumber() << "] " << str << std::endl;
    }

    void Logger::logError(const std::string &str) {
        std::cerr << "[" << Singleton::getInstance().getTickNumber() << "] " << str << std::endl;
    }

    void Logger::mapCreated(arg_t width, arg_t height) {
        std::stringstream ss;
        ss << "MAP_CREATED " << width << " " << height;
        logInfo(ss.str());
    }

    void Logger::unitSpawned(id_t id, UNIT_TYPE type, coordinate_t &coord) {
        std::stringstream ss;
        ss << "UNIT_SPAWNED ID " << id << " TYPE " << UNIT_TYPEtoString(type) << " ON " << coord.x << " "
           << coord.y;
        logInfo(ss.str());
    }

    void Logger::marchStarted(id_t id, const coordinate_t &from, const coordinate_t &to) {
        std::stringstream ss;
        ss << "MARCH_STARTED ID " << id << " FROM " << from.x << " " << from.y << " TO " << to.x << " " << to.y;
        logInfo(ss.str());
    }

    void Logger::marchFinished(id_t id, const coordinate_t &point) {
        std::stringstream ss;
        ss << "MARCH_FINISHED ID " << id << " AT " << point.x << " " << point.y;
        logInfo(ss.str());
    }

    void Logger::receivedDamage(id_t whoId, power_t damage, id_t fromId, hp_t remainingHp) {
        std::stringstream ss;
        ss << "RECIVED_DAMAGE ID " << whoId << " DAMAGE " << damage << " FROM_ID " << fromId
           << " REMAINING_HP " << remainingHp;
        logInfo(ss.str());
    }

    void Logger::unitDied(id_t id) {
        std::stringstream ss;
        ss << "UNIT_DIED ID " << id;
        logInfo(ss.str());
    }
}