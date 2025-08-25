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
    glm::vec3 direction{};
    glm::vec3 up{};
    glm::vec3 right{};
    glm::vec3 front{};

    Camera();

    glm::mat4 getView() const;

    void moveForward(float units);
    void moveBackward(float units);
    void moveLeft(float units);
    void moveRight(float units);
    void moveUp(float units);
    void moveDown(float units);

    void changeYaw(float value);
    void changePitch(float value);

private:
    void updateDirection();
    float yaw;
    float pitch;
    glm::vec3 worldUp = { 0.0f, 1.0f, 0.0f };
};


#endif //PROC_GEN_GAME_CAMERA_H