//
// Created by alst on 12.02.24.
//
#include "warrior.h"
#include "../game/constants.h"
#include "../common/logger.h"
#include "../game/game.h"

namespace Game{
    Warrior::Warrior(const id_t &id, const hp_t &hp, const power_t &strength)
            :Unit(id, hp),
             MeleeAttacker( id, hp, range_t{WARRIOR_MELEE_DISTANCE_START, WARRIOR_MELEE_DISTANCE_END}, strength){}

    //Melee attack or moveUnit - only 1 activity at a 1 tick
    void Warrior::doTickActivity(){
        if( MeleeAttacker::attack() == ATTACK_STATE::NO_ONE_TO_ATTACK){
            move();
        }
    }
}
