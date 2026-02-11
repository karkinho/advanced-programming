#ifndef DSTAR_HPP
#define DSTAR_HPP

#include "Settings.hpp"
#include <queue>
#include <vector>
#include "grid/GridAdapter.hpp"
#include <cstddef>

struct Node {
    size_t row, column;
    float k1, k2;

    Node() = default;

    Node(size_t r, size_t c, float a, float b )
        : row(r), column(c), k1(a), k2(b) {}

    float TopKey() {
        if ( k1 > k2 ) {
            return k2;
        } 
        return k1;
    }

    bool operator==(const Node& other) const {
        return row == other.row && column == other.column;
    }
    bool operator<(const Node& other) const {
        if (k1 != other.k1)
            return k1 < other.k1;
        return k2 < other.k2;
    }
    bool operator<=(const Node& other) const {
        if (k1 != other.k1)
            return k1 <= other.k1;
        return k2 <= other.k2;
    }
};

struct Compare {
    bool operator()(const Node& a, const Node& b) const {
        if (a.k1 != b.k1)
            return a.k1 > b.k1; 
        return a.k2 > b.k2;      
    }
    bool comp( std::pair< float , float > a, std::pair< float , float > b ) {
        if (a.first != b.first)
            return a.first > b.first; 
        return a.second > b.second;      
    }
};

class DStar
{
protected:

    Size_t2 start, end, last, agentStart;
    Node startNode, endNode;
    float acumulation = 0;
    std::priority_queue< Node , std::vector< Node > , Compare> pQueue;
    std::vector< std::vector< float > > distGrid, distGridCopy;
    GridAdapter * gridAdapter;
    
    float Heuristic( Size_t2 start , Size_t2 goal );
    std::pair< float , float > CalculateKey( const Node& a );
    void Predecesors( std::vector< Size_t2 > & predecesors , Size_t2 pos );
    float Cost( Size_t2 from , Size_t2 to );
    void UpdateVertex( Size_t2 pos );
    bool IsOnQueue( Size_t2 pos );
    void RemoveQueue( Size_t2 pos );
    void UpdateQueue( Size_t2 pos );
    bool IsAgentSelf( Size_t2 pos );
public:
    DStar( Size_t2 start , Size_t2 end );
    ~DStar();
    void CalculateShortesPath();
    void Replan( Agent * agent );
    std::vector< std::vector< size_t > > GetDistances();
};

#endif