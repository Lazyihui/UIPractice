#ifndef B_GAME_H__
#define B_GAME_H__

#include "Ctx.h"
#include "D_Cell.h"

void B_Game_Enter(Ctx *ctx) {
    // 画cell
    //  生成格子
    for (int y = 0; y <= 400; y += std_cell) {
        Vector2 pos = Vector2_New(-8, y);

        pos = Vector2Scale(pos, std_cell);
        
        D_Cell_Spawn(ctx, 1, pos);
    }
    PlogNoArg("aa444\r\n");
}

#endif