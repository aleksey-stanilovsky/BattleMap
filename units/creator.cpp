//
// Created by alst on 12.02.24.
//
#include "creator.h"
#include "interface/unit.h"
#include "warrior.h"
#include "archer.h"

namespace Game{
    std::string UNIT_TYPEtoString(UNIT_TYPE type){
        switch (type) {
            case UNIT_TYPE::WARRIOR: return "Warrior";
            case UNIT_TYPE::ARCHER: return "Archer";
        }
        return "None";
    }

    std::shared_ptr<Unit> createUnit( const std::vector<arg_t> &commandArgs, UNIT_TYPE type )
    {
        std::shared_ptr<Unit> p{};
        switch (type)
        {
            case UNIT_TYPE::WARRIOR:
            {
                id_t id = commandArgs[0];
                hp_t hp = commandArgs[3];
                power_t strength = commandArgs[4];
                p = std::make_shared<Warrior>(id, hp, strength);
            }
            break;
            case UNIT_TYPE::ARCHER:
            {
                id_t id = commandArgs[0];
                hp_t hp = commandArgs[3];
                power_t strength = commandArgs[4];
                rng_t range = commandArgs[5];
                power_t agility = commandArgs[6];
                p = std::make_shared<Archer>(id, hp, strength, range, agility);
            }
            break;
        }
        return std::move(p);
    }
}
