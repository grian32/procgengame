#include <raylib.h>
#include "camera.h"
#include "movement.h"

int main(void) {
    InitWindow(1024, 1024, "Proc Gen Game");

    DisableCursor();

    Camera3D camera = { 0 };

    camera.position = (Vector3){0.0f, 2.0f, 4.0f};
    camera.target = (Vector3){0.0f, 2.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        PUpdateCamera(&camera);
        UpdateMovement(&camera);

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 20.0f, 22.0f }, WHITE);
        DrawCube((Vector3){ 0.0f, 4.0f, 0.0f }, 2.0f, 2.0f, 2.0f, GRAY);

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}