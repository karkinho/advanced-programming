#include "raylib.hpp"
#include "grid/Grid.hpp"
#include "grid/GridAdapterFactory.hpp"
#include "initialization/BaseHandler.hpp"
#include "initialization/GetInfo.hpp"
#include "initialization/InitFactorys.hpp"
#include "initialization/InitGrid.hpp"
#include "initialization/InitUi.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>
#include <cmath>
#include "actions/Invoker.hpp"
#include "input/InputPublisher.hpp"
#include "common/Clock.hpp"

int main() {
    bool running = true;
    BaseHandler * initialization;
    initialization = ( BaseHandler * ) new GetInfo();
    initialization->AddEnd( ( BaseHandler * ) new InitFactorys() );
    initialization->AddEnd( ( BaseHandler * ) new InitGrid() );
    initialization->AddEnd( ( BaseHandler * ) new InitUi() );
    initialization->Execute( InicializationVariables() );

    std::ofstream appendFile("log.csv");
    appendFile.close();

    delete initialization;

    GridAdapter * gridAdapter = GridAdapterFactory::GetGridAdapterFactory()->GetAdapter();

    while( running ) {
        Clock::GetClock()->Tick();
        if( WindowShouldClose() ) {
            running = false;
        }
        if( IsWindowFocused() ) {
            InputPublisher::GetInputPublisher()->Input();
        }

        BeginDrawing( );  
        ClearBackground( BLACK );
        gridAdapter->DrawGrid();
        

        EndDrawing();
    } 
    CloseWindow();
    return 0;
}
