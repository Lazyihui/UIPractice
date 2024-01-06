#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Common.h"
#include "Ctx.h"
#include "App_UI.h"
#include "TM_Tower.h"
#include "Template.h"
static Ctx *ctx;

int main() {
    ctx = (Ctx *)calloc(1, sizeof(Ctx));
    assert(ctx != NULL);
    InitWindow(800, 600, "UI");
    SetTargetFPS(60);
    ctx_Inti(ctx);
    CtxUIInit(ctx->ctx_UI);
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (IsKeyPressed(KEY_A)) {


            App_UI_PanelTower_Open(ctx->ctx_UI, Vector2_New(400, 300));
            
            int manifest[3] = {1, 2, 3};
            
            for (int i = 0; i < 3; i++) {
                int typeID = manifest[i];
                TM_Tower *towerTM = Template_GetTower(ctx->tpl, typeID);
                App_UI_PanelTower_Add(ctx->ctx_UI, towerTM->typeID, towerTM->iconColor);
            }
            if (IsKeyPressed(KEY_B)) {
                PlogNoArg("B");
                App_UI_PanelTower_Close(ctx->ctx_UI);
            }
        }
        App_UI_PanelTower_Draw(ctx->ctx_UI);
        DrawCircle(0, 0, 100, RED);
        EndDrawing();
    }
    CloseWindow();
    ctxfree(ctx);
    return 0;
}