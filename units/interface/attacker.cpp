//
// Created by alst on 15.02.24.
//
#include "attacker.h"
#include "../../game/game.h"

namespace Game{
    Attacker::Attacker(const id_t &id, const hp_t &hp, const range_t &range, const power_t &power)
            : Unit(id, hp), _range(range), _power(power){}

    ATTACK_STATE Attacker::attack() const{
        auto target = Singleton::getInstance().chooseEnemy(_id, _range);
        if(target != nullptr ){
            Singleton::getInstance().doDmg(target, _power );
            return ATTACK_STATE::ATTACK_SUCESS;
        }
        return ATTACK_STATE::NO_ONE_TO_ATTACK;
    }
}
