#ifndef E_CELL_H__
#define E_CELL_H__

#include "Common.h"

typedef struct E_Cell {
    int ID;     // 哪一个
    int typeID; // 哪一种
    Vector2 pos;

    ShapeType shapeType;
    Color color;
    Vector2 size;
    /* data */
} E_Cell;

void E_Cell_Draw(E_Cell *cell){

    if(cell->shapeType==SHAPE_TYPE_CIRCLE){
        DrawCircle(cell->pos.x,cell->pos.y,cell->size.x/2,cell->color);
    }
    if(cell->shapeType==)
}

#endif