//
// Created by grian on 8/22/25.
//

#include <iostream>
#include <GLFW/glfw3.h>

#include "render/Camera.h"

bool isKeyPressed(GLFWwindow *window, const int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

struct MouseData {
    Camera* cam;
    float* lastX;
    float* lastY;
    bool* firstMouse;
};

void processInput(GLFWwindow *window, Camera& camera, float deltaTime, MouseData* data) {
    if (isKeyPressed(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, true);
    }

    const float cameraSpeed = 4.5f * deltaTime;
    if (isKeyPressed(window, GLFW_KEY_W)) {
        camera.moveForward(cameraSpeed);
    }
    if (isKeyPressed(window, GLFW_KEY_S)) {
        camera.moveBackward(cameraSpeed);
    }
    if (isKeyPressed(window, GLFW_KEY_A)) {
        camera.moveLeft(cameraSpeed);
    }
    if (isKeyPressed(window, GLFW_KEY_D)) {
        camera.moveRight(cameraSpeed);
    }
    if (isKeyPressed(window, GLFW_KEY_SPACE)) {
        camera.moveUp(cameraSpeed);
    }
    if (isKeyPressed(window, GLFW_KEY_LEFT_SHIFT)) {
        camera.moveDown(cameraSpeed);
    }

    glfwSetWindowUserPointer(window, data);
    glfwSetCursorPosCallback(window, [](GLFWwindow* w, double xPos, double yPos) {
        auto c = static_cast<MouseData*>(glfwGetWindowUserPointer(w));
        if (*c->firstMouse) {
            *c->lastX = xPos;
            *c->lastY = yPos;
            *c->firstMouse = false;
            return;
        }

        float xOffset = xPos - *c->lastX;
        float yOffset = *c->lastY - yPos;

        *c->lastX = xPos;
        *c->lastY = yPos;

        const float sens = 0.1f;
        xOffset *= sens;
        yOffset *= sens;

        c->cam->changeYaw(xOffset);
        c->cam->changePitch(yOffset);
    });
}
