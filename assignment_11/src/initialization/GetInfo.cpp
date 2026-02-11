#include "initialization/GetInfo.hpp"
#include <iostream>


GetInfo::GetInfo() : BaseHandler() {
}

GetInfo::~GetInfo() {

}

InicializationVariables GetInfo::Execute( InicializationVariables variables ) {
    variables.windowSize = Vector4{ 0 , 0 , 800 , 800 };

    size_t option;
    std::cout << "1 - Square | 2 - Hexa" << std::endl;
    std::cin >> option;

    switch (option)
    {
        case 1:
            variables.typeGrid = SQUARE;
            break;
        case 2:
            variables.typeGrid = HEXA;
            break;
        default:
            variables.typeGrid = SQUARE;
            break;
    }   

    std::cout << "Size of The Grid" << std::endl;
    std::cin >> option;

    variables.rows = option;
    variables.columns = option;

    return BaseHandler::Execute( variables );
}

