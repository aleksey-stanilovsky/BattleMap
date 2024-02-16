//
// Created by alst on 14.02.24.
//

#ifndef BATTLEMAP_GAME_H
#define BATTLEMAP_GAME_H

#include <vector>
#include <memory>
#include <fstream>

#include "../units/interface/unit.h"
#include "../common/constants.h"
#include "../units/creator.h"

namespace Game{
    class Singleton
    {
    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(Singleton& ) = delete;

        static Singleton& getInstance();

        int parseScenario(int argc, char* argv[]);

        void moveUnit( id_t id);
        void doDmg( const std::shared_ptr<Unit> &target, power_t dmg );
        std::shared_ptr<Unit> chooseEnemy(id_t id, const range_t &range);
        size_t& getTickNumber();

    private:
        Singleton() = default;

        static coordinate_t calcNextMoveCell(const coordinate_t &unit, const coordinate_t &target );
        static std::shared_ptr<Unit> chooseEnemyFromGroup(const std::vector<std::shared_ptr<Unit>> &enemies);
        static auto getCommandAndItsArgsCount(const std::string &line );
        static auto strToNums(const std::string& str);
        static auto getArgs(const std::string &line, const command_t &cmd);
        int parseFirstLine(const std::string &line);
        int parseLine(const std::string &line);

        void createMap(std::vector<arg_t> &commandArgs);
        int spawn(const std::vector<arg_t> &commandArgs, UNIT_TYPE type);
        void wait(std::vector<arg_t> commandArgs);
        void march(std::vector<arg_t> commandArgs);
        void doTickActivity();
        void cleanKilledUnits();
        void moveUnitToPoint(id_t id, const coordinate_t &moveTo);
        std::vector<std::shared_ptr<Unit>> checkForEnemies( id_t id, const range_t &range);
        bool isPointReachable(id_t id, const range_t &range, const coordinate_t &point);

        std::vector<std::vector<std::shared_ptr<Unit>>> map;
        std::unordered_map<id_t, coordinate_t> idsPoint;
        std::vector<std::shared_ptr<Unit>> units;
        std::vector<std::shared_ptr<Unit>> KilledUnits;

        std::unordered_map<id_t, coordinate_t> unitsDestination;
        std::unordered_map<id_t, std::shared_ptr<Unit>> unitFightsWith;

        size_t tickNumber{};
    };
}


#endif //BATTLEMAP_GAME_H
