//
// Created by alst on 12.02.24.
//

#include <string>
#include "unit.h"
#include "../../game/game.h"

namespace Game{
    Unit::Unit( const size_t &id, const hp_t &hp )
            :_id(id), _hp(hp){}

    size_t Unit::getId() const {
        return _id;
    }

    hp_t Unit::getHp() const{
        return _hp;
    }

    void Unit::setHp(const hp_t &hp){
        _hp = hp;
    }

    void Unit::move() const{
        Singleton::getInstance().moveUnit(_id);
    }
}
