#include <cmath>
#include <glad/glad.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "input.h"
#include "render/Shader.h"
#include "util.h"
#include "stb_image.h"
#include "render/Camera.h"
#include "render/Texture.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "failed to initalize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window =
        glfwCreateWindow(1000, 1000, "Proc Gen Game", nullptr, nullptr);

    if (!window) {
        fprintf(stderr, "faled to create glfw window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        fprintf(stderr, "failed to initialize glad\n");
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float vertices[] = {
        // pos              // col
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, // bottom right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // bottom left
        -0.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f,// top right
        -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f,// top right
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    Shader shaderProgram("../shaders/v.glsl", "../shaders/f.glsl");

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    Texture tex("../grass.jpg");
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1000.0f / 1000.0f, 0.1f, 100.0f);

    Camera camera{};

    shaderProgram.use();
    shaderProgram.setUniformMat4f("model", model);
    shaderProgram.setUniformMat4f("projection", projection);


    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    float lastX = 500;
    float lastY = 500;
    bool firstMouse = true;

    auto* data = new MouseData{ &camera, &lastX, &lastY, &firstMouse};

    while (!glfwWindowShouldClose(window)) {
        float currFrame = glfwGetTime();
        deltaTime = currFrame - lastFrame;
        lastFrame = currFrame;

        processInput(window, camera, deltaTime, data);

        glClearColorRgb(135, 206, 235);
        glClear(GL_COLOR_BUFFER_BIT);

        tex.bind();
        shaderProgram.use();

        shaderProgram.setUniformMat4f("view", camera.getView());

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    delete data;
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}