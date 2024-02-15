//
// Created by alst on 15.02.24.
//

#ifndef BATTLEMAP_ATTACKER_H
#define BATTLEMAP_ATTACKER_H

#include "unit.h"

namespace Game{
    class Attacker : virtual public Unit
    {
    public:
        Attacker() = delete;
        explicit Attacker(const id_t &id, const hp_t &hp, const range_t &range, const power_t &power );
    protected:
        [[nodiscard]] ATTACK_STATE attack() const;

        range_t _range;
        power_t _power;
    };
}
#endif //BATTLEMAP_ATTACKER_H
