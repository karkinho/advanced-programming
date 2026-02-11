#ifndef CELL_HPP
#define CELL_HPP

#include "raylib.hpp"
#include "Settings.hpp"
#include "common/Dynamic.hpp"
#include "common/Collisor.hpp"

class Cell
    {
    protected:
        Size_t2 position;
        Dynamic * dynamic;
        Collisor * collisor;
    public:
        Cell( Size_t2 position , Dynamic * dynamic , Collisor * collisor );
        virtual ~Cell();
        virtual void Draw();
        Size_t2 GetPosition();
        Dynamic * GetDynamic();
        Collisor * GetCollisor();
        virtual void Tick();
    };


#endif