#include "grid/Grid.hpp"
#include "agent/Agent.hpp"
#include "common/Clock.hpp"

Grid::Grid( size_t rows , size_t columns ) {
    this->rows = rows;
    this->columns = columns;
    for ( size_t row = 0 ; row < rows ; row++ ) {
        std::vector< std::deque< Cell * > > aux;
        for ( size_t column = 0 ; column < columns ; column++ ) {
            aux.push_back( std::deque< Cell * >(0) );
        }   
        grid.push_back( aux );
        aux.clear();
    }
    gridAdapter = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter();
}

Grid::~Grid() {

}

std::vector< Obstacle * > Grid::GetObstacles() {
    return obstacles;
}

Grid * Grid::GetGrid() {
    return gridptr;
}

void Grid::Initialize( size_t rows , size_t columns ) {
    gridptr = new Grid( rows , columns );
}

void Grid::Draw() {
    for ( size_t index = 0 ; index < obstacles.size() ; index++ ) {
        obstacles[index]->Draw();
    }
    for ( size_t index = 0 ; index < agents.size() ; index++ ) {
        agents[index]->Draw();
    }
}

void Grid::DrawAgents() {
    for ( size_t index = 0 ; index < agents.size() ; index++ ) {
        agents[index]->DrawAgent();
    }
}

std::vector< std::vector < std::deque< Cell * > > > Grid::GetBoard() {
    return grid;
}

void Grid::AddObstacle( OBSTACLE_TYPE type , Size_t2 position ) {
    if( grid[position.x][position.y].size() > 0 ) {
        return;
    }  
    changedThisTick.push_back( position );
    obstacles.push_back( ObstacleFactory::GetObstacleFactory()->Create( type , position ) );
    grid[position.x][position.y].push_back( ( Cell * )obstacles.back() );
}

std::deque< Cell * > Grid::GetCell( Size_t2 position ) {
    return grid[position.x][position.y];
}

void Grid::AddAgent( Size_t2 position ) {  
    if( grid[position.x][position.y].size() > 0 ) {
        return;
    }  
    agents.push_back( new Agent( position , position , 60 , gridAdapter->GetRadiusOfCell() / 2 , GREEN ) );
    grid[position.x][position.y].push_back( ( Cell* )agents.back() );
    
}

void Grid::SetAgentEnd( Size_t2 position ) {
    agents.back()->SetEndPoint( position );
}

Cell * Grid::Remove( Size_t2 position ) {
    std::deque < Cell * > cellBuff;
    Cell * cell;
    for ( size_t index = 0 ; index < obstacles.size() ; index++ ) {
        if( obstacles[index]->GetPosition().x == position.x && obstacles[index]->GetPosition().y == position.y ) {
            cellBuff = grid[position.x][position.y];
            for ( size_t i = 0 ; i < cellBuff.size() ; i++ ) {
                if( cellBuff[i] == ( Cell * ) obstacles[index] ) {
                    cell = cellBuff[i];
                    grid[position.x][position.y].erase( grid[position.x][position.y].begin() + i );
                    break;
                }
            }
            obstacles.erase( obstacles.begin() + index );  
            return cell;
        }
    }
    for ( size_t index = 0 ; index < agents.size() ; index++ ) {
        if( ( agents[index]->GetStart().x == position.x && agents[index]->GetStart().y == position.y ) || ( agents[index]->GetEnd().x == position.x && agents[index]->GetEnd().y == position.y ) ) {
            cellBuff = grid[agents[index]->GetPosition().x][agents[index]->GetPosition().y];
            for ( size_t i = 0 ; i < cellBuff.size() ; i++ ) {
                if( cellBuff[i] == ( Cell * ) agents[index] ) {
                    cell = cellBuff[i];
                    grid[agents[index]->GetPosition().x][agents[index]->GetPosition().y].erase( grid[agents[index]->GetPosition().x][agents[index]->GetPosition().y].begin() + i );
                    break;
                }
            }
            agents.erase( agents.begin() + index );  
            return cell;
        }
    }
    return nullptr;
}

void Grid::RecalculateAgents() {
    if( agents.size() == 0 ) {
        return;
    }
    for ( size_t index = 0 ; index < agents.size() - 1 ; index++ ) {
        agents[index]->CalculatePath();
    }
    if( agents[agents.size() - 1]->GetEndState() ) {
        agents[agents.size() - 1]->CalculatePath();
    }
}

bool Grid::GetEndAgentState() {
    if( agents.size() == 0 ) {
        return true;
    }
    return agents[agents.size() - 1]->GetEndState();
}

void Grid::MoveAgents() {
    Clock::GetClock()->StartTimer();
    for ( size_t index = 0 ; index < agents.size() ; index++ ) {
        agents[index]->Tick();
    }
    changedLastTick.clear();
    changedLastTick = changedThisTick;
    changedThisTick.clear();
    Clock::GetClock()->StopGetTimer();
}

std::pair< std::vector< Size_t2 > , std::vector< Size_t2 > > Grid::GetChanges() {
    return std::make_pair( changedThisTick , changedLastTick ); 
}

void Grid::MoveAgent( Size_t2 from , Size_t2 to , Agent * agent ) {
    std::deque< Cell * > cellFrom = grid[from.x][from.y];
    for ( size_t i = 0 ; i < cellFrom.size() ; i++ ) {
        if( cellFrom[i] == ( Cell * ) agent ) {
            grid[from.x][from.y].erase( grid[from.x][from.y].begin() + i );
            break;
        }
    }
    grid[to.x][to.y].push_back( ( Cell * ) agent );
    changedThisTick.push_back( from );
    changedThisTick.push_back( to );
}

void Grid::ResetAgents() {
    for ( size_t index = 0 ; index < agents.size() ; index++ ) {
        agents[index]->Reset();
    }
}