//
// Created by grian on 8/21/25.
//

#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

const float SPEED = 0.015f;
const float FALL_AMOUNT = 0.015f;
const Vector3 JUMP_VEC = (Vector3){0.0f, 1.0f, 0.0f};

void UpdateMovement(Camera *camera) {
    // maybe compute this inside the ifs? kinda dodgy tho since i can reuse forward
    const Vector3 forward = Vector3Subtract(camera->target, camera->position);
    const Vector3 backward = Vector3Negate(forward);
    const Vector3 right = Vector3CrossProduct(forward, camera->up);
    const Vector3 left = Vector3Negate(right);

    if (IsKeyDown(KEY_W)) {
        Vector3 newPos = Vector3Add(camera->position, Vector3Scale(forward, SPEED));
        newPos.y = camera->position.y;
        Vector3 newTarget = Vector3Add(camera->target, Vector3Scale(forward, SPEED));
        newTarget.y = camera->target.y;

        camera->position = newPos;
        camera->target = newTarget;
    } else if (IsKeyDown(KEY_S)) {
        Vector3 newPos = Vector3Add(camera->position, Vector3Scale(backward, SPEED));
        newPos.y = camera->position.y;
        Vector3 newTarget = Vector3Add(camera->target, Vector3Scale(backward, SPEED));
        newTarget.y = camera->target.y;

        camera->position = newPos;
        camera->target = newTarget;
    }

    if (IsKeyDown(KEY_D)) {
        Vector3 newPos = Vector3Add(camera->position, Vector3Scale(right, SPEED));
        newPos.y = camera->position.y;
        Vector3 newTarget = Vector3Add(camera->target, Vector3Scale(right, SPEED));
        newTarget.y = camera->target.y;

        camera->position = newPos;
        camera->target = newTarget;
    } else if (IsKeyDown(KEY_A)) {
        Vector3 newPos = Vector3Add(camera->position, Vector3Scale(left, SPEED));
        newPos.y = camera->position.y;
        Vector3 newTarget = Vector3Add(camera->target, Vector3Scale(left, SPEED));
        newTarget.y = camera->target.y;

        camera->position = newPos;
        camera->target = newTarget;
    }

    if (IsKeyPressed(KEY_SPACE)) {
        if (camera->position.y > 2.0f) {
            return;
        }

        Vector3 newPos = Vector3Add(camera->position, Vector3Add(camera->up, JUMP_VEC));
        camera->position = newPos;

        Vector3 newTarget = Vector3Add(camera->target, Vector3Add(camera->up, JUMP_VEC));
        camera->target = newTarget;
    }

    if (camera->position.y > 2.0f) {
        camera->position.y -= FALL_AMOUNT;
        camera->target.y -= FALL_AMOUNT;
    }
}