//
// Created by alst on 15.02.24.
//

#ifndef BATTLEMAP_MELEEATTACKER_H
#define BATTLEMAP_MELEEATTACKER_H

#include "attacker.h"

namespace Game{
    class MeleeAttacker : public Attacker
    {
    public:
        MeleeAttacker() = delete;
        explicit MeleeAttacker(id_t id, hp_t hp, const range_t &range, power_t power );
    };
}

#endif //BATTLEMAP_MELEEATTACKER_H
