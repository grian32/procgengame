#include <raylib.h>
#include <raymath.h>

const float SENSITIVITY = 0.003f;

void PUpdateCamera(Camera *camera) {
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