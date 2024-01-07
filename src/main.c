#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Common.h"
#include "Ctx.h"
#include "App_UI.h"
#include "TM_Tower.h"
#include "Template.h"
#include "D_UI.h"
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
            D_UI_Toggle(ctx);
        }

        App_UI_PanelTower_Draw(ctx->ctx_UI);
        DrawCircle(0, 0, 100, RED);
        EndDrawing();
    }
    CloseWindow();
    ctxfree(ctx);
    return 0;
}