#ifndef FACTOR_H__
#define FACTOR_H__

#include "E_Cell.h"
#include "Ctx.h"
#include "S_ID.h"

E_Cell* Factory_Create_Cell(Ctx* ctx, int typeID, Vector2 pos) {

    TM_Cell* tm = Template_GetCell(ctx->tpl, typeID);
    if (tm == NULL) {
        printf("err : Template_GetCell() return NULL\n");
        return NULL;
    }

    E_Cell* cell = (E_Cell*)malloc(sizeof(E_Cell));
    cell->ID = ctx->s_id->cellIDRecord++;
    cell->typeID = typeID;
    cell->pos = pos;
    cell->shapeType = tm->shapeType;
    cell->size = tm->size;
    cell->color = tm->color;

    return cell;
}
#endif