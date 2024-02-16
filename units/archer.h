//
// Created by alst on 12.02.24.
//

#ifndef BATTLEMAP_ARCHER_H
#define BATTLEMAP_ARCHER_H

#include "interface/rangeAttacker.h"
#include "interface/meleeAttacker.h"

namespace Game{
    class Archer : public RangeAttacker, public MeleeAttacker
    {
    public:
        Archer() = delete;
        explicit Archer(id_t id, hp_t hp, power_t strength, rng_t rangeEnd, power_t agility);
        void doTickActivity() override;
    };
}

#endif //BATTLEMAP_ARCHER_H
