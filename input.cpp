//
// Created by grian on 8/22/25.
//

#include <GLFW/glfw3.h>

#include "render/Camera.h"

bool isKeyPressed(GLFWwindow *window, const int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

void processInput(GLFWwindow *window, Camera& camera, float deltaTime) {
    if (isKeyPressed(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, true);
    }


    const float cameraSpeed = 4.5f * deltaTime;
    if (isKeyPressed(window, GLFW_KEY_W)) {
        camera.pos += cameraSpeed * camera.front;
    }
    if (isKeyPressed(window, GLFW_KEY_S)) {
        camera.pos -= cameraSpeed * camera.front;
    }
    if (isKeyPressed(window, GLFW_KEY_A)) {
        camera.pos -= glm::normalize(glm::cross(camera.front, camera.up)) * cameraSpeed;
    }
    if (isKeyPressed(window, GLFW_KEY_D)) {
        camera.pos += glm::normalize(glm::cross(camera.front, camera.up)) * cameraSpeed;
    }
}
