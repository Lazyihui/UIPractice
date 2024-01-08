#ifndef TEMPLATE_H__
#define TEMPLATE_H__

#include "TM_Tower.h"
#include "TM_Cell.h"
typedef struct Template {
    // tower
    TM_Tower *towers;
    int toeweLength;
    
    // cell
    TM_Cell *cells;
    int cellLenth;
} Template;

void Template_Cell_Init(Template *tpl) {

    tpl->cellLenth = 0;
    tpl->cells = (TM_Cell *)malloc(sizeof(TM_Cell) * 20);

    TM_Cell *cell = tpl->cells;
    TM_Cell c1;
    c1.typeID = 1;
    c1.shapeType = SHAPE_TYPE_RECT;
    c1.color = BLUE;
    c1.size.x = std_towerCell;
    c1.size.y = std_towerCell;

    cell[tpl->cellLenth++] = c1;
}

void Template_Tower_Init(Template *tpl) {
    tpl->toeweLength = 0;
    tpl->towers = (TM_Tower *)calloc(10, sizeof(TM_Tower));

    TM_Tower *towers = tpl->towers;
    TM_Tower t1 = TM_Tower_Create(1, 1, 1, RED, RED, SHAPE_TYPE_CIRCLE, Vector2_New(std_cell * 3, std_cell * 3));
    TM_Tower t2 = TM_Tower_Create(2, 1, 1, GREEN, GREEN, SHAPE_TYPE_CIRCLE, Vector2_New(std_cell * 3, std_cell * 3));
    TM_Tower t3 = TM_Tower_Create(3, 1, 1, PINK, PINK, SHAPE_TYPE_CIRCLE, Vector2_New(std_cell * 3, std_cell * 3));
    towers[tpl->toeweLength++] = t1;
    towers[tpl->toeweLength++] = t2;
    towers[tpl->toeweLength++] = t3;
}

void Template_free(Template *tpl) {
    free(tpl->towers);
    free(tpl);
}
TM_Tower *Template_GetTower(Template *tpl, int typeID) {

    for (int i = 0; i < tpl->toeweLength; i++) {
        if (tpl->towers[i].typeID == typeID) {
            return &tpl->towers[i];
        }
    }
    Plog("No TypeID:%d", typeID);
    return NULL;
}

TM_Cell *Template_GetCell(Template *tpl, int typeID) {
    for (int i = 0; i < tpl->cellLenth; i++) {
        if (tpl->cells[i].typeID == typeID) {
            return &tpl->cells[i];
        }
    }
    Plog("No TypeID:%d", typeID);
    return NULL;
}
#endif