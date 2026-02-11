#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "raylib.hpp"
#include "grid/Cell.hpp"
#include <tuple> 
#include <vector>
#include "Settings.hpp"
#include "agent/Agent.hpp"
#include "obstacle/Obstacle.hpp"
#include <algorithm>
#include "Settings.hpp"

typedef struct {
    size_t dist, row, collum;
} pDist;

class Dijkstra
{
protected:
    Dijkstra();
    inline static Dijkstra * dijkstra = nullptr;
public:
    ~Dijkstra();
    static Dijkstra * GetDijkstra();
    std::vector< std::vector< size_t > > FindPath( Size_t2 start , Size_t2 end );
};

#endif