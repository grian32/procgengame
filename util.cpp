//
// Created by grian on 8/22/25.
//
#include "util.h"

#include <glad/glad.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/gl.h>


void glClearColorRgb(int red, int green, int blue) {
    glClearColor(static_cast<float>(red)/255, static_cast<float>(green)/255, static_cast<float>(blue)/255, 1.0f);
}

void glCheckAndPrintShaderErrors(unsigned int shader) {
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        printf("ERROR::SHADER::COMPILATION_FAILED\n%s\n", infoLog);
    }
}

void glCheckAndPrintProgramErrors(unsigned int program) {
    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        printf("ERROR::SHADER::PROGRAM_LINK_FAILED\n%s\n", infoLog);
    }
}

std::string readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "failed to open file: " << filename << std::endl;
        return {};
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

unsigned int loadShader(const std::string& vertexShaderPath, GLenum type) {
    std::string shaderSource = readFile(vertexShaderPath);
    if (shaderSource.empty()) return 0;

    unsigned int shader = glCreateShader(type);
    const char* srcPtr = shaderSource.c_str();
    glShaderSource(shader, 1, &srcPtr, nullptr);
    glCompileShader(shader);
    glCheckAndPrintShaderErrors(shader);

    return shader;
}

// takes in both vertex & fragment shaders and returns the compiled shader program
unsigned int loadProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glCheckAndPrintProgramErrors(shaderProgram);

    return shaderProgram;
}
