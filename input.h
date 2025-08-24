//
// Created by grian on 8/22/25.
//

#ifndef PROC_GEN_GAME_INPUT_H
#define PROC_GEN_GAME_INPUT_H
#include <GLFW/glfw3.h>

#include "render/Camera.h"

void processInput(GLFWwindow *window, Camera& camera, float deltaTime);

#endif //PROC_GEN_GAME_INPUT_H