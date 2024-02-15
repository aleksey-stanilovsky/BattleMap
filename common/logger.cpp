//
// Created by alst on 14.02.24.
//
#include "../units/interface/unit.h"
#include "logger.h"

#include <sstream>
#include "iostream"
#include "../game/game.h"

void Logger::logInfo(const std::string &str){
    std::cout << "[" << Game::Singleton::getInstance().getTickNumber() << "] " << str << std::endl;
}

void Logger::logError(const std::string &str){
    std::cerr << "[" << Game::Singleton::getInstance().getTickNumber() << "] " << str << std::endl;
}

void Logger::mapCreated(const Game::arg_t &width, const Game::arg_t &height) {
    std::stringstream ss;
    ss << "MAP_CREATED " << width << " " << height;
    logInfo(ss.str());
}

void Logger::unitSpawned(const Game::id_t &id, const Game::UNIT_TYPE &type, const Game::coordinate_t &coord) {
    std::stringstream ss;
    ss << "UNIT_SPAWNED ID " << id << " TYPE " << Game::UNIT_TYPEtoString(type) << " ON " << coord.x << " " << coord.y;
    logInfo(ss.str());
}

void Logger::marchStarted(const Game::id_t &id, const Game::coordinate_t &from, const Game::coordinate_t &to) {
    std::stringstream ss;
    ss << "MARCH_STARTED ID " << id << " FROM " << from.x << " " << from.y << " TO " << to.x << " " << to.y;
    logInfo(ss.str());
}

void Logger::marchFinished(const Game::id_t &id) {
    std::stringstream ss;
    ss << "MARCH_FINISHED ID " << id;
    logInfo(ss.str());
}

void Logger::receivedDamage(const Game::id_t &whoId,
                            const Game::power_t &damage,
                            const Game::id_t &fromId,
                            const Game::hp_t &remainingHp) {
    std::stringstream ss;
    ss << "RECIVED_DAMAGE ID " << whoId << " DAMAGE " << damage << " FROM_ID " << fromId << " REMAINING_HP " << remainingHp;
    logInfo(ss.str());
}

void Logger::unitDied(const Game::id_t &id) {
    std::stringstream ss;
    ss << "UNIT_DIED ID " << id;
    logInfo(ss.str());
}
