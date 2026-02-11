#include "grid/GridAdapterFactory.hpp"

GridAdapterFactory::GridAdapterFactory( TYPE_GRID typeGrid , size_t rows , size_t columns , Vector4 windowSize ) {
    this->typeGrid = typeGrid;
    this->rows = rows;
    this->columns = columns;
    this->windowSize = windowSize;
}

GridAdapterFactory::~GridAdapterFactory() {
    delete gridAdapterFactory;
}

GridAdapterFactory * GridAdapterFactory::GetGridAdapterFactory() {
    return gridAdapterFactory;
}

GridAdapter * GridAdapterFactory::GetAdapter() {
    switch (typeGrid)
    {
    case HEXA:
        return ( GridAdapter * )new HexaAdapter( rows , columns , windowSize );
        break;
    case SQUARE:
        return ( GridAdapter * )new SquareAdapter( rows , columns , windowSize );
        break;
    
    default:
        return nullptr;
        break;
    }
}

void GridAdapterFactory::Initialize( TYPE_GRID typeGrid ,  size_t rows , size_t columns , Vector4 windowSize ) {
    gridAdapterFactory = new GridAdapterFactory( typeGrid , rows , columns , windowSize );
}
