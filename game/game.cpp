//
// Created by alst on 14.02.24.
//
#include <sstream>
#include "game.h"
#include "../common/logger.h"

namespace Game{
    Singleton& Singleton::getInstance() {
        static Singleton instance;
        return instance;
    }

    coordinate_t Singleton::calcNextMoveCell(const coordinate_t &unit, const coordinate_t &target ){
        // Calc the coordinate_t difference between the unit and the target
        auto dx = static_cast<long long> (target.x - unit.x);
        auto dy = static_cast<long long> (target.y - unit.y);

        // Normalize the directions to determine one of the 8 directions
        auto moveX = (dx != 0) ? (dx / std::abs(dx)) : 0; // -1 for left, 1 for right, 0 if we do not moveUnit horizontally
        auto moveY = (dy != 0) ? (dy / std::abs(dy)) : 0; // -1 for up, 1 for down, 0 if we do not moveUnit vertically

        // Coordinates to moveUnit to
        return {unit.x + moveX, unit.y + moveY};
    }

    void Singleton::createMap(std::vector<arg_t> &commandArgs)
    {
        arg_t w = commandArgs[0];
        arg_t h = commandArgs[1];

        map.resize(h);
        map.shrink_to_fit();

        for (auto& row : map) {
            row.resize(w, nullptr);
            row.shrink_to_fit();
        }
        Logger::mapCreated(w, h);
    }

    std::vector<std::shared_ptr<Unit>> Singleton::checkForEnemies( id_t id, const range_t &range ) {
        std::vector<std::shared_ptr<Unit>> unitsWithinRange{};
        size_t rows = map.size();
        size_t cols = map[0].size();
        coordinate_t &unitPoint = idsPoint[id];

        for (long dx = -static_cast<long long >(range.end); dx <= range.end; dx++) {
            for (long dy = -static_cast<long long >(range.end); dy <= range.end; dy++) {
                long newX = static_cast<long long >(unitPoint.x) + dx;
                long newY = static_cast<long long >(unitPoint.y) + dy;

                // Check if the cell is located within the map and the search radii
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    long distance = std::max(std::abs(dx), std::abs(dy));
                    if (distance >= range.start && distance <= range.end) {
                        // add coordinates to the vector if we find a unit
                        if (map[newX][newY] != nullptr) {
                            unitsWithinRange.push_back(map[newX][newY]);
                        }
                    }
                }
            }
        }
        return unitsWithinRange;
    }

//by lowest hp if equal then by id
    std::shared_ptr<Unit> Singleton::chooseEnemyFromGroup(const std::vector<std::shared_ptr<Unit>> &enemies){
        if ( enemies.empty() )
            return nullptr;

        std::shared_ptr<Unit> result = enemies[0];

        for ( const auto& enemie : enemies ) {
            if (enemie->getHp() < result->getHp() || // If HP lower
               (enemie->getHp() == result->getHp() && enemie->getId() < result->getId())) {//HP the same but ID is lower
               result = enemie;
            }
        }
        return result;
    }

    void Singleton::cleanKilledUnits(){
        for(auto &unit_p : KilledUnits){
            auto id = unit_p->getId();
            auto coord = idsPoint[id];

            auto unit_it = std::find(units.begin(), units.end(), unit_p);
            if ( unit_it != units.end() ){
                units.erase(unit_it);
            }
            else{
                Logger::logError("cleanKilledUnits err - no unit id in units container");
            }

            map[coord.x][coord.y] = nullptr;
            idsPoint.erase(id);
            unitsDestination.erase(id);
            unitFightsWith.erase(id);

            Logger::unitDied(id);
        }
        KilledUnits.clear();
    }

    auto Singleton::getCommandAndItsArgsCount(const std::string &line ){
        for(auto it = commandsAndItsArgsCount.begin(); it != commandsAndItsArgsCount.end(); ++it ) {
            if( line.starts_with(it->first ) ) {
                return it;
            }
        }
        return commandsAndItsArgsCount.end();
    }

    auto Singleton::strToNums(const std::string &str) {
        std::vector<arg_t> outNums;
        std::istringstream iss(str);
        arg_t num;
        while (iss >> num) {
            outNums.push_back(num);
        }
        return outNums;
    }

    auto Singleton::getArgs(const std::string &line, const command_t &cmd)
    {
        return strToNums(line.substr(cmd.length(), line.length() - cmd.length()));
    }

    int Singleton::parseFirstLine(const std::string &line) {
        auto const commandAndItsArgsCount_it = getCommandAndItsArgsCount(line);
        if(commandAndItsArgsCount_it == commandsAndItsArgsCount.end() )
        {
            Logger::logError("First have to be CREATE_MAP - wrong line \"" + line + '\"');
            return 1;
        }

        std::vector<arg_t> commandArgs = getArgs(line, commandAndItsArgsCount_it->first);
        if( commandArgs.size() != commandAndItsArgsCount_it->second )
        {
            Logger::logError(
                    commandAndItsArgsCount_it->first +
                    " First have to be CREATE_MAP - not valid amount of args \"" + line + "\"");
            return 1;
        } else if (commandAndItsArgsCount_it->first == CREATE_MAP) {
            createMap(commandArgs);
        }
        else{
            Logger::logError(commandAndItsArgsCount_it->first +
                            " First have to be CREATE_MAP - wrong line \"" + line + "\"");
            return 1;
        }
        return 0;
    }

    int Singleton::parseLine(const std::string &line) {
        auto const commandAndItsArgsCount_it = getCommandAndItsArgsCount(line);
        if( commandAndItsArgsCount_it == commandsAndItsArgsCount.end() )
        {
            Logger::logError("wrong line \"" + line + '\"');
            return 1;
        }
        std::vector<arg_t> commandArgs = getArgs(line, commandAndItsArgsCount_it->first);
        if(commandArgs.size() != commandAndItsArgsCount_it->second){
            Logger::logError(commandAndItsArgsCount_it->first + " not valid amount of args \"" + line + "\"");
            return 1;
        } else if (commandAndItsArgsCount_it->first == CREATE_MAP) {
            Logger::logError(commandAndItsArgsCount_it->first + " call only one on the first line of script");
            return 2;
        } else if (commandAndItsArgsCount_it->first == SPAWN_WARRIOR) {
            spawn(commandArgs, UNIT_TYPE::WARRIOR);
        } else if (commandAndItsArgsCount_it->first == SPAWN_ARCHER) {
            spawn(commandArgs, UNIT_TYPE::ARCHER);
        } else if (commandAndItsArgsCount_it->first == MARCH) {
            march(commandArgs);
        } else if (commandAndItsArgsCount_it->first == WAIT) {
            wait(commandArgs);
        }

        return 0;
    }

    int Singleton::parseScenario(int argc, char* argv[])
    {
        std::ifstream file{};
        std::string line{};

        if (argc != 2) {
            Logger::logError("You need to pass scenario file as an argument.\n"
                             + std::string("Usage: ") + argv[0] + " <filename>");
            return 1;
        }

        file.open(argv[1]);
        if (!file.is_open()) {
            Logger::logError("Could not open file " + std::string(argv[1]));
            return 1;
        }

        getline(file, line);
        int rc = parseFirstLine(line);
        if(rc)
            return rc;

        while (getline(file, line)) {
            parseLine(line);
            //if should be perfect there is a need to return rc in case of error occurrence - now them ignored
        }

        file.close();
        return 0;
    }

    void Singleton::march(std::vector<arg_t> commandArgs){
        id_t id = commandArgs[0];
        coordinate_t moveTo = {commandArgs[1], commandArgs[2] };

        auto mapSizeX = map.size();
        auto mapSizeY = map[0].size();
        if(moveTo.x >= mapSizeX || moveTo.y >= mapSizeY )
        {
            Logger::logError("id(" + std::to_string(id) + ") can not MARCH - it is out of map coordinates, mapSize(" +
                             std::to_string(mapSizeX) + ", " + std::to_string(mapSizeY) +
                             ") but we want to march to cell with index" +
                             std::to_string(moveTo.x) + " " + std::to_string(moveTo.y));
            return;
        }
        unitsDestination[id] = moveTo;
        coordinate_t moveFrom = idsPoint[id];
        Logger::marchStarted(id, moveFrom, moveTo);
    }

    void Singleton::doTickActivity(){
        for(auto &unit : units)
        {
            unit->doTickActivity();
            cleanKilledUnits();
        }
    }

    void Singleton::wait(std::vector<arg_t> commandArgs){
        arg_t ticks = commandArgs[0];
        for(size_t i =0; i < ticks; ++i){
            doTickActivity();
            ++tickNumber;
        }
    }

    int Singleton::spawn(const std::vector<arg_t> &commandArgs, UNIT_TYPE type){
        id_t id = commandArgs[0];
        coordinate_t point = {commandArgs[1], commandArgs[2]};

        if (idsPoint.find(id) != idsPoint.end()){
            Logger::logError("can not spawn " + UNIT_TYPEtoString(type) +" with id(" + std::to_string(id) + ") on " +
            std::to_string(point.x) + " " + std::to_string(point.y) + " - id is already taken");
            return 1;
        }
        auto mapSizeX = map.size();
        auto mapSizeY = map[0].size();

        auto unit_p = createUnit(commandArgs, type);
        if(point.x >= mapSizeX || point.y >= mapSizeY )
        {
            Logger::logError("can not spawn " + UNIT_TYPEtoString(type) +" with id(" + std::to_string(id) + ") on " +
                             std::to_string(point.x) + " " + std::to_string(point.y) +
                             " - this is out of map coordinates, mapSize(" + std::to_string(mapSizeX) + ", " +
                             std::to_string(mapSizeY) + ")");
            return 2;
        }

        auto unitInCell = map[point.x][point.x];
        if(unitInCell != nullptr)
        {
            Logger::logError("can not spawn " + UNIT_TYPEtoString(type) +" with id(" + std::to_string(id) + ") on " +
                             std::to_string(point.x) + " " + std::to_string(point.y) +
                             " - this point is taken by id (" + std::to_string(unitInCell->getId()) + ")");
            return 3;
        }
        map[point.x][point.y] = unit_p;
        idsPoint[id] = point;
        units.push_back(unit_p);

        Logger::unitSpawned(id, type, point);
        return 0;
    }

    void Singleton::moveUnitToPoint( id_t id, const coordinate_t &moveTo){
        coordinate_t moveFrom = idsPoint[id];
        auto curUnit_p = map[moveFrom.x][moveFrom.y];

        map[moveFrom.x][moveFrom.y] = nullptr;
        map[moveTo.x][moveTo.y] = curUnit_p;
        idsPoint[id] = moveTo;

        if(unitsDestination[id].x == moveTo.x && unitsDestination[id].y == moveTo.y ){
            unitsDestination.erase(id);
            Logger::marchFinished(id, moveTo);
        }
    }

    std::shared_ptr<Unit> Singleton::chooseEnemy(id_t id, const range_t &range){
        std::shared_ptr<Unit> chosenEnemy_p{nullptr};

        auto chosenEnemy_it = unitFightsWith.find(id);
        if(chosenEnemy_it != unitFightsWith.end()) {
            chosenEnemy_p = chosenEnemy_it->second;
        }
        else {
            auto nearEnemies = checkForEnemies(id, range);
            chosenEnemy_p = chooseEnemyFromGroup(nearEnemies);
            if( chosenEnemy_p  != nullptr )
                unitFightsWith[id] = chosenEnemy_p;
        }

        return std::move(chosenEnemy_p);
    }

    void Singleton::moveUnit( id_t id){
        auto move_it = unitsDestination.find(id);
        if(move_it != unitsDestination.end() ){
            auto target{move_it->second};
            auto unit{idsPoint[id]};

            coordinate_t cellToMove = calcNextMoveCell(unit, target );
            //this may remove - because in basic logic we can wight near enemy first and if there is no one then we go
            if(map[cellToMove.x][cellToMove.y] == nullptr)
                moveUnitToPoint(id, cellToMove);
        }
    }

    void Singleton::doDmg( const std::shared_ptr<Unit> &target, power_t dmg) {
        hp_t newHp{0};

        hp_t curHp{target->getHp()};
        if (curHp > dmg)
            newHp = curHp - dmg;
        else
            KilledUnits.push_back(target);

        target->setHp(newHp);
        Logger::receivedDamage(target->getId(), dmg, target->getId(), newHp);
    }

    size_t& Singleton::getTickNumber() {
        return tickNumber;
    }
}

