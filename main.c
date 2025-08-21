#include <raylib.h>
#include <raymath.h>

const float SENSITIVITY = 0.003f;

void UpdateCameraG(Camera *camera) {
    Vector2 mouse = GetMouseDelta();

    float yawAngle = -mouse.x * SENSITIVITY;
    float pitchAngle = -mouse.y * SENSITIVITY;

    Vector3 up = camera->up;

    Vector3 targetPos = Vector3Subtract(camera->target, camera->position);

    targetPos = Vector3RotateByAxisAngle(targetPos, up, yawAngle);

    Vector3 right = Vector3CrossProduct(targetPos, up);

    targetPos = Vector3RotateByAxisAngle(targetPos, right, pitchAngle);
    camera -> target = Vector3Add(camera->position, targetPos);
}

int main(void) {
    InitWindow(1024, 1024, "Proc Gen Game");

    DisableCursor();

    Camera3D camera = { 0 };

    camera.position = (Vector3){0.0f, 2.0f, 4.0f};
    camera.target = (Vector3){0.0f, 2.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {
        UpdateCameraG(&camera);

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