#ifndef D_UI_H__
#define D_UI_H__

#include "App_UI.h"
#include "Ctx.h"

void D_UI_Open(Ctx *ctx) {

    App_UI_PanelTower_Open(ctx->ctx_UI, Vector2_New(400, 300));

    int manifest[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        int typeID = manifest[i];
        TM_Tower *towerTM = Template_GetTower(ctx->tpl, typeID);
        App_UI_PanelTower_Add(ctx->ctx_UI, towerTM->typeID, towerTM->iconColor);
    }
}

void D_UI_Close(Ctx *ctx) {
    App_UI_PanelTower_Close(ctx->ctx_UI);
}

void D_UI_Toggle(Ctx *ctx) {
    
    if (App_UI_PanelTower_IsOpen(ctx->ctx_UI)) {
        D_UI_Close(ctx);
    } else {
        D_UI_Open(ctx);
    }
}

#endif