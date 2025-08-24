//
// Created by grian on 8/24/25.
//

#include "Camera.h"

Camera::Camera() {
    pos = glm::vec3(0.0f, 0.0f, 3.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::getView() const {
    return glm::lookAt(pos, pos+front, up);
}
