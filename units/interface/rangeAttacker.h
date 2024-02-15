//
// Created by alst on 15.02.24.
//

#ifndef BATTLEMAP_RANGEATTACKER_H
#define BATTLEMAP_RANGEATTACKER_H

#include "attacker.h"

namespace Game{
    class RangeAttacker : public Attacker
    {
    public:
        RangeAttacker() = delete;
        explicit RangeAttacker(const id_t &id, const hp_t &hp, const range_t &range, const power_t &power );
    };
}


#endif //BATTLEMAP_RANGEATTACKER_H
