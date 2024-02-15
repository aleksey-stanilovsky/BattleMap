//
// Created by alst on 15.02.24.
//
#include "meleeAttacker.h"

namespace Game{
    MeleeAttacker::MeleeAttacker(const id_t &id, const hp_t &hp, const range_t &range, const power_t &power)
            : Attacker(id, hp, range, power){}
}
