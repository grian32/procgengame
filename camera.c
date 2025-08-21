#include <raylib.h>
#include <raymath.h>

const float SENSITIVITY = 0.003f;

void PUpdateCamera(Camera *camera) {
    Vector2 mouse = GetMouseDelta();

    float yawAngle = -mouse.x * SENSITIVITY;
    float pitchAngle = -mouse.y * SENSITIVITY;

    Vector3 up = Vector3Normalize(camera->up);

    Vector3 targetPos = Vector3Subtract(camera->target, camera->position);
    Vector3 forward = Vector3Normalize(targetPos);

    targetPos = Vector3RotateByAxisAngle(targetPos, up, yawAngle);

    Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, up));

    targetPos = Vector3RotateByAxisAngle(targetPos, right, pitchAngle);
    camera -> target = Vector3Add(camera->position, targetPos);
}