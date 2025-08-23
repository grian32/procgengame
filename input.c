//
// Created by grian on 8/22/25.
//

#include <stdbool.h>
#include <GLFW/glfw3.h>

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
