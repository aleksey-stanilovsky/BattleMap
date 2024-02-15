//
// Created by alst on 12.02.24.
//
#include "archer.h"

namespace Game{
    Archer::Archer(const id_t &id, const hp_t &hp, const power_t &strength, const rng_t &distance, const power_t &agility)
            :
            Unit(id, hp),
            MeleeAttacker(id, hp, range_t{ARCHER_MELEE_DISTANCE_START, ARCHER_MELEE_DISTANCE_END}, strength ),
            RangeAttacker(id, hp, range_t{ARCHER_RANGE_DISTANCE_START, distance}, agility )
            {}

    //Range attack or Melee attack or moveUnit - only 1 activity at a time
    void Archer::doTickActivity(){
        if( MeleeAttacker::attack() == ATTACK_STATE::NO_ONE_TO_ATTACK){
            if( RangeAttacker::attack() == ATTACK_STATE::NO_ONE_TO_ATTACK) {
                move();
            }
        }
    }
}
