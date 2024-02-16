//
// Created by alst on 15.02.24.
//
#include "attacker.h"
#include "../../game/game.h"
#include "../../common/logger.h"

namespace Game{
    Attacker::Attacker(id_t id, hp_t hp, const range_t &range, power_t power)
            : Unit(id, hp), _range(range), _power(power){}

    ATTACK_STATE Attacker::attack() const{
        auto target = Singleton::getInstance().chooseEnemy(_id, _range);
        if(target != nullptr ){
            Singleton::getInstance().doDmg(target, _power );
            Logger::receivedDamage( target->getId(), _power, _id , target->getHp() );
            return ATTACK_STATE::ATTACK_SUCESS;
        }
        return ATTACK_STATE::NO_ONE_TO_ATTACK;
    }
}
