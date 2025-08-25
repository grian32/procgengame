//
// Created by grian on 8/24/25.
//

#include "Camera.h"

Camera::Camera() {
    pos = glm::vec3(0.0f, 0.0f, 3.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    right = glm::normalize(glm::cross(front, up));
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
