//
// Created by grian on 8/24/25.
//

#include "Camera.h"

#include <iostream>

Camera::Camera() {
    yaw = -90.0f;
    pitch = 0;
    pos = glm::vec3(0.0f, 0.0f, 3.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    direction = glm::vec3{};

    updateDirection();
}

glm::mat4 Camera::getView() const {
    return glm::lookAt(pos, pos+front, up);
}

void Camera::moveForward(const float units) {
    pos += front * units;
}
void Camera::moveBackward(const float units) {
    pos -= front * units;
}
void Camera::moveLeft(const float units) {
    pos -= right * units;
}
void Camera::moveRight(const float units) {
    pos += right * units;
}

void Camera::changeYaw(const float value) {
    yaw += value;
    updateDirection();
}

void Camera::changePitch(const float value) {
    pitch += value;

    if (pitch > 89.0f) {
        pitch = 89.0f;
    } else if (pitch < -89.0f) {
        pitch = -89.0f;
    }

    updateDirection();
}

void Camera::updateDirection() {
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(direction);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}
