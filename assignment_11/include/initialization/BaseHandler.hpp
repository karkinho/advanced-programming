#ifndef BASEHANDLER_HPP
#define BASEHANDLER_HPP

#include "raylib.hpp"
#include "Settings.hpp"
#include "grid/GridAdapter.hpp"
#include "actions/Invoker.hpp"

typedef struct InicializationVariables {
    Vector4 windowSize;
    TYPE_GRID typeGrid;
    size_t rows, columns;
} InicializationVariables;

class BaseHandler
{
protected:
    BaseHandler * next = nullptr;
public:
    BaseHandler();
    virtual ~BaseHandler();
    void SetNext( BaseHandler * baseHandler );
    void AddEnd( BaseHandler * baseHandler );
    virtual InicializationVariables Execute( InicializationVariables variables );
};

#endif
