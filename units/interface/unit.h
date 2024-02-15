//
// Created by alst on 12.02.24.
//

#ifndef BATTLEMAP_UNIT_H
#define BATTLEMAP_UNIT_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <memory>

#include "../../game/constants.h"

namespace Game{
    class Unit
    {
    public:
        Unit() = delete;
        explicit Unit(const id_t &id, const hp_t &hp);

        virtual void doTickActivity() = 0;

        [[nodiscard]] id_t getId() const;
        [[nodiscard]] hp_t getHp() const;
        void setHp(const hp_t &hp);

    protected:
        void move() const;

        size_t _id;
        hp_t _hp;
    };
}

#endif //BATTLEMAP_UNIT_H
