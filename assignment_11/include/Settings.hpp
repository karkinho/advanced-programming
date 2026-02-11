#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "raylib.hpp"
#include <cstddef>
#include <cmath> 

#define MENU_LINE_COLOR WHITE
#define MENU_LINE_WIDTH 4

#define END_COLOR BLUE
#define START_COLOR GREEN
#define PATH_COLOR ORANGE
#define AGENT_COLOR RED
#define PATH_WIDTH 2

enum INPUT_ACTION {
    ADD_MUD,
    ADD_WALL,
    ADD_AGENT,
    REMOVE,
    NONE,
};

enum INPUT {
    LEFT_CLICK,
    RIGHT_CLICK,
    ONE,
    TWO,
    THREE,
    FOUR,
};

enum OBSTACLE_TYPE {
    WALL,
    MUD,
};

enum TYPE_GRID {
    SQUARE,
    HEXA,
};
enum COLLISION_METHOD {
    DIRECT_COMMUNICATION,
    INDIRECT_COMMUNICATION,
    NO_COMMUNICATION,
};

typedef struct Size_t2 {
    size_t x;
    size_t y;
    bool operator==(const Size_t2& other) const {
        if ( x == other.x && y == other.y ) {
            return true;
        }
        return false;
    }

} IntVector2;

#pragma once

inline auto multVectorByScalar = []( Vector2 v , float scalar ) {
    return Vector2{ v.x * scalar , v.y * scalar };
};

inline auto dirVector = [] ( Vector2 a , Vector2 b ) {
    return Vector2{
        b.x - a.x , b.y - a.y
    };
};

inline auto normalize = [] (Vector2 v) {
    float len = std::sqrt(v.x * v.x + v.y * v.y);
    return Vector2{
        v.x / len,
        v.y / len
    };
};

inline auto compareFloat = []( Vector2 a , Vector2 b , float delta ) {
    return std::abs( a.x - b.x ) < delta && std::abs( a.y - b.y ) < delta;
};

#endif