#ifndef D_CELL_H__
#define D_CELL_H__

#include "Ctx.h"
#include "E_Cell.h"
#include "RP_Cell.h"
#include "Factory.h"

void D_Cell_Spawn(Ctx *ctx, int typeID, Vector2 pos) {

    E_Cell *cell = Factory_Create_Cell(ctx, typeID, pos);
    PlogNoArg("D_Cell_Spawn");
    assert(cell!=NULL);
    if (cell != NULL) {
        RP_Cell_Add(ctx->rp_cell, cell);
    }
}

#endif