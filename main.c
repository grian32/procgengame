#include <raylib.h>

int main(void) {
    InitWindow(640, 640, "Proc Gen Game");

    while (!WindowShouldClose()) {
        BeginDrawing();

        DrawRectangle(0, 0, 40, 40, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}