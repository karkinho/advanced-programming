#ifndef GRIDADAPTERFACTORY_HPP
#define GRIDADAPTERFACTORY_HPP

#include "raylib.h"
#include "Settings.hpp"
#include "Cell.hpp"
#include <vector>
#include "grid/GridAdapter.hpp"
#include "grid/HexaAdapter.hpp"
#include "grid/SquareAdapter.hpp"

class GridAdapterFactory
{
protected:
    size_t rows, columns;
    Vector4 windowSize; 
    GridAdapterFactory( TYPE_GRID typeGrid , size_t rows , size_t columns , Vector4 windowSize );
    inline static GridAdapterFactory * gridAdapterFactory = nullptr;
    TYPE_GRID typeGrid;
public:
    ~GridAdapterFactory();
    static GridAdapterFactory * GetGridAdapterFactory();
    static void Initialize( TYPE_GRID typeGrid ,  size_t rows , size_t columns , Vector4 windowSize );
    GridAdapter * GetAdapter();
};









#endif