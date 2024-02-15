//
// Created by alst on 13.02.24.
//

#ifndef BATTLEMAP_CONSTANRS_H
#define BATTLEMAP_CONSTANRS_H

namespace Game {
    using arg_t = size_t;

    using id_t = size_t;
    using hp_t = size_t;

    using coord_t = size_t;
    struct coordinate_t{
        coord_t x;
        coord_t y;
    };

    using command_t = std::string;
    using commandArgsCnt_t = const unsigned int;
    const std::unordered_map<command_t, commandArgsCnt_t> commandsAndItsArgsCount =
    {
          {"CREATE_MAP", 2}
        , {"SPAWN_WARRIOR", 5}
        , {"SPAWN_ARCHER", 7}
        , {"MARCH", 3}
        , {"WAIT", 1}
    };

    enum class UNIT_TYPE
    {
        WARRIOR
        , ARCHER
    };

    enum class ATTACK_STATE{
        NO_ONE_TO_ATTACK = 0
        , ATTACK_SUCESS = 1
    };

    using power_t = size_t;
    using rng_t = size_t;
    struct range_t{
        rng_t start;
        rng_t end;
    };
    constexpr rng_t WARRIOR_MELEE_DISTANCE_START {1};
    constexpr rng_t WARRIOR_MELEE_DISTANCE_END {1};

    constexpr rng_t ARCHER_MELEE_DISTANCE_START {WARRIOR_MELEE_DISTANCE_START};
    constexpr rng_t ARCHER_MELEE_DISTANCE_END {WARRIOR_MELEE_DISTANCE_END};
    constexpr rng_t ARCHER_RANGE_DISTANCE_START {2};
  //constexpr range_t ARCHER_RANGE_DISTANCE_END {<RangeVarible>};
}


#endif //BATTLEMAP_CONSTANRS_H
