#include "algorithm/DStar.hpp"
#include "grid/GridAdapterFactory.hpp"
#include <tuple>
#include <cstdlib>
#include "agent/Agent.hpp"

DStar::~DStar() {
    delete gridAdapter;
    distGrid.clear();
}

DStar::DStar( Size_t2 start , Size_t2 end ) {
    gridAdapter = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter();
    this->agentStart = start;
    this->start = start;
    this->end = end;
    this->last = start;

    distGrid = std::vector< std::vector< float > >( gridAdapter->GetRows() , std::vector< float >( gridAdapter->GetCollums() , std::numeric_limits<float>::infinity() ) );
    distGridCopy = distGrid;

    distGrid[end.x][end.y] = 0;
    
    startNode = Node{ start.x , start.y , 0 , 0 };
    endNode = Node{ end.x , end.y , 0 , 0 };
    std::pair< float , float > aux = CalculateKey( endNode );
    endNode.k1 = aux.first;
    endNode.k2 = aux.second;
    aux = CalculateKey( startNode );
    startNode.k1 = aux.first;
    startNode.k2 = aux.second;
    pQueue.push( endNode );
}

float DStar::Heuristic( Size_t2 a, Size_t2 b) {
    return std::abs(static_cast<long long>(a.x) - static_cast<long long>(b.x)) + 
           std::abs(static_cast<long long>(a.y) - static_cast<long long>(b.y));
}

bool DStar::IsAgentSelf( Size_t2 pos ) {
    for (auto &&element : gridAdapter->GetCell( pos ) )
    {
        if( element->GetDynamic() != nullptr && ( ( Agent * ) element)->GetStart() == agentStart && gridAdapter->GetCell( pos ).size() == 1 ) {
            return true;
        }
    }
    return false;
}

float DStar::Cost( Size_t2 from , Size_t2 to ) {
    if( IsAgentSelf( from ) || IsAgentSelf( to ) ) {
        return Heuristic( from , to );
    } 
    if( gridAdapter->GetCell( from ).size() > 0 ) {
        return std::numeric_limits<float>::infinity();
    }
    if( gridAdapter->GetCell( to ).size() > 0 ) {
        return std::numeric_limits<float>::infinity();
    }
    
    return Heuristic( from , to );
}

void DStar::CalculateShortesPath(  ) {
    std::pair< float , float > aux, oldKey, newKey;
    Node current;
    std::vector< Size_t2 > predecesors, predecesorsAux;
    while ( !pQueue.empty() && ( pQueue.top() < startNode || distGrid[start.x][start.y] != distGridCopy[start.x][start.y] ) ) {
        current = pQueue.top();
        oldKey = std::make_pair( current.k1 , current.k2 );
        newKey = CalculateKey( current );
        pQueue.pop();
        if( oldKey < newKey  ) {
            current.k1 = newKey.first;
            current.k2 = newKey.second;
            pQueue.push( current );
        } else if( distGridCopy[current.row][current.column] > distGrid[current.row][current.column] ) {
            distGridCopy[current.row][current.column] = distGrid[current.row][current.column];

            Predecesors( predecesors , Size_t2{ current.row , current.column } );
            for (const auto& pred : predecesors) {
                if (!(pred == end)) {
                    distGrid[pred.x][pred.y] = std::min(distGrid[pred.x][pred.y], 
                        distGridCopy[current.row][current.column] + Cost(pred, {current.row, current.column}));
                }
                UpdateVertex(pred);
            }
        } else {
            float distGridCopyOld = distGridCopy[current.row][current.column];
            distGridCopy[current.row][current.column] = std::numeric_limits<float>::infinity();
            Predecesors( predecesors , Size_t2{ current.row , current.column } );
            predecesors.push_back( Size_t2{ current.row , current.column } );
            for (const auto& p : predecesors) {
                if (distGrid[p.x][p.y] == Cost(p, {current.row, current.column}) + distGridCopyOld) {
                    if (!(p == end)) {
                        float min_rhs = std::numeric_limits<float>::infinity();
                        Predecesors(predecesorsAux, p);
                        for (const auto& succ : predecesorsAux) {
                            float val = Cost(p, succ) + distGridCopy[succ.x][succ.y];
                            if (val < min_rhs) min_rhs = val;
                        }
                        distGrid[p.x][p.y] = min_rhs;
                    }
                }
                UpdateVertex(p);
            }
        }
        aux = CalculateKey( startNode );
        startNode.k1 = aux.first;
        startNode.k2 = aux.second;
    }   
}

std::vector< std::vector< size_t > > DStar::GetDistances() {
    std::vector< std::vector< size_t > > ans;
    std::vector< size_t > aux;
    for ( size_t x = 0 ; x < distGrid.size() ; x++ ) {
        for ( size_t y = 0 ; y < distGrid[x].size() ; y++ ) {
            if( distGrid[x][y] == std::numeric_limits<float>::infinity() ) {
                aux.push_back( INT_MAX );    
            } else {
                aux.push_back( distGrid[x][y] );
            }
        }
        ans.push_back( aux );
        aux.clear();
    }
    return ans;
}

bool DStar::IsOnQueue( Size_t2 pos ) {
    std::priority_queue< Node , std::vector< Node > , Compare> aux = pQueue;
    while ( !aux.empty() ) {
        if( pos == Size_t2{ aux.top().row , aux.top().column } ) {
            return true;
        }
        aux.pop();
    }
    return false;
}

void DStar::RemoveQueue( Size_t2 pos ) {
    std::priority_queue< Node , std::vector< Node > , Compare> aux;
    while ( !pQueue.empty() ) {
        if( pos == Size_t2{ pQueue.top().row , pQueue.top().column } ) {
            pQueue.pop();
            break;
        }
        aux.push( pQueue.top() );
        pQueue.pop();
    }
    while ( !aux.empty() )
    {
        pQueue.push( aux.top() );
        aux.pop();
    }
}

void DStar::UpdateQueue(Size_t2 pos) {
    std::vector<Node> nodes;
    nodes.reserve(pQueue.size());
    while (!pQueue.empty()) {
        nodes.push_back(pQueue.top());
        pQueue.pop();
    }

    for (auto &n : nodes) {
        if (pos.x == n.row && pos.y == n.column) {
            auto newKey = CalculateKey(n);
            n.k1 = newKey.first;
            n.k2 = newKey.second;
        }
    }

    for (const auto &n : nodes) pQueue.push(n);
}

void DStar::UpdateVertex(Size_t2 pos) {
    // 1. If it's not the goal, recalculate the rhs (distGrid)
    if (!(pos == end)) {
        float min_rhs = std::numeric_limits<float>::infinity();
        std::vector<Size_t2> successors = gridAdapter->WhoIsMyNeighburs(pos);
        
        for (const auto& succ : successors) {
            float val = Cost(pos, succ) + distGridCopy[succ.x][succ.y];
            if (val < min_rhs) min_rhs = val;
        }
        distGrid[pos.x][pos.y] = min_rhs;
    }

    // 2. Remove from queue if it's already there to update its priority
    if (IsOnQueue(pos)) {
        RemoveQueue(pos);
    }

    // 3. If inconsistent, put it (back) on the queue with a new key
    if (distGridCopy[pos.x][pos.y] != distGrid[pos.x][pos.y]) {
        Node node(pos.x, pos.y, 0, 0);
        std::pair<float, float> keys = CalculateKey(node);
        node.k1 = keys.first;
        node.k2 = keys.second;
        pQueue.push(node);
    }
}
void DStar::Predecesors(std::vector<Size_t2> &predecesors, Size_t2 pos) {
    predecesors.clear();
    predecesors = gridAdapter->WhoIsMyNeighburs(pos);
}


std::pair< float , float > DStar::CalculateKey( const Node& a ) {
    float g_rhs = std::min(distGridCopy[a.row][a.column], distGrid[a.row][a.column]);
    return std::make_pair( g_rhs + Heuristic( start , Size_t2{ a.row , a.column } ) + this->acumulation , g_rhs );
}

void DStar::Replan(Agent * agent) {
    Size_t2 robotPos = agent->GetPosition();
    std::pair<std::vector<Size_t2>, std::vector<Size_t2>> changesPair = gridAdapter->GetChanges();
    
    if (changesPair.first.empty() && changesPair.second.empty()) return;

    // Standard D* Lite: Update k_m (accumulation) and current start
    this->acumulation += Heuristic(this->last, robotPos);
    this->last = robotPos;
    this->start = robotPos;
    this->startNode.row = robotPos.x;
    this->startNode.column = robotPos.y;

    // For every changed cell, update it and its neighbors
    auto processChange = [&](const Size_t2& changedPos) {
        UpdateVertex(changedPos);
        std::vector<Size_t2> neighbors = gridAdapter->WhoIsMyNeighburs(changedPos);
        for (auto& n : neighbors) {
            UpdateVertex(n);
        }
    };

    for (auto& pos : changesPair.first) processChange(pos);
    for (auto& pos : changesPair.second) processChange(pos);

    CalculateShortesPath(); 
}