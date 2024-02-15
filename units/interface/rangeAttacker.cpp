//
// Created by alst on 15.02.24.
//
#include "rangeAttacker.h"

namespace Game {
    RangeAttacker::RangeAttacker( id_t id, hp_t hp, const range_t &range, const power_t power)
            : Attacker(id, hp, range, power) {}
}