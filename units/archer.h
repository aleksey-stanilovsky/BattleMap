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
        explicit Archer(const id_t &id,
                        const hp_t &hp,
                        const power_t &strength,
                        const rng_t &distance,
                        const power_t &agility);
        void doTickActivity() override;
    };
}

#endif //BATTLEMAP_ARCHER_H
