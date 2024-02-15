//
// Created by alst on 12.02.24.
//

#ifndef BATTLEMAP_CREATR_H
#define BATTLEMAP_CREATR_H

#include <memory>
#include "interface/unit.h"
#include "../common/constants.h"

namespace Game{
    std::string UNIT_TYPEtoString(UNIT_TYPE type);
    std::shared_ptr<Unit> createUnit( const std::vector<arg_t> &commandArgs, UNIT_TYPE type );
}


#endif //BATTLEMAP_CREATR_H
