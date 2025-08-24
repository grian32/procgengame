//
// Created by grian on 8/24/25.
//

#ifndef PROC_GEN_GAME_CAMERA_H
#define PROC_GEN_GAME_CAMERA_H
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera {
public:
    glm::vec3 pos{};
    // glm::vec3 Target;
    // glm::vec3 Direction;
    glm::vec3 up{};
    // glm::vec3 Right;
    glm::vec3 front{};
    Camera();
    glm::mat4 getView() const;
};


#endif //PROC_GEN_GAME_CAMERA_H