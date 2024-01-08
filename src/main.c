#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Common.h"
#include "Ctx.h"
#include "App_UI.h"
#include "TM_Tower.h"
#include "Template.h"
#include "D_UI.h"
#include "B_Game.h"

static Ctx *ctx;

int main() {
    ctx = (Ctx *)calloc(1, sizeof(Ctx));
    assert(ctx != NULL);
    InitWindow(800, 600, "UI");
    SetTargetFPS(60);
    ctx_Inti(ctx);
    CtxUIInit(ctx->ctx_UI);
    Rectangle rect;
    rect.height = 100;
    rect.width = 100;
    rect.y = 100;
    rect.x = 100;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(rect, GREEN);
        bool isClick = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        Vector2 mouse = GetMousePosition();
        bool isInside = IsRectInsideMouseRec(rect, mouse);

        if (isClick && isInside) {
            D_UI_Toggle(ctx);
        }
        PlogNoArg("s\r\n");
        B_Game_Enter(ctx);

        App_UI_PanelTower_Draw(ctx->ctx_UI);
        DrawCircle(0, 0, 100, RED);
        EndDrawing();
    }
    CloseWindow();
    ctxfree(ctx);
    return 0;
}