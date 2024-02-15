//
// Created by alst on 15.02.24.
//
#include "meleeAttacker.h"

namespace Game{
    MeleeAttacker::MeleeAttacker(id_t id, hp_t hp, const range_t &range, power_t power)
            : Attacker(id, hp, range, power){}
}
