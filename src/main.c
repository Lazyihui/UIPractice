#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"

int main() {

    InitWindow(800, 600, "UI");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}