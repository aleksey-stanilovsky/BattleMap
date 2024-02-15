//
// Created by alst on 12.02.24.
//

#ifndef BATTLEMAP_WARRIOR_H
#define BATTLEMAP_WARRIOR_H

#include "interface/meleeAttacker.h"

namespace Game{
    class Warrior : public MeleeAttacker
    {
    public:
        Warrior() = delete;
        explicit Warrior(const id_t &id, const hp_t &hp, const power_t &strength);

        void doTickActivity() override;
    };
}


#endif //BATTLEMAP_WARRIOR_H
