//
// Created by grian on 8/22/25.
//
#include "util.h"

#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>


void glClearColorRgb(int red, int green, int blue) {
    glClearColor((float)red/255, (float)green/255, (float)blue/255, 1.0f);
}

void glCheckAndPrintShaderErrors(unsigned int shader) {
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::COMPILATION_FAILED\n%s\n", infoLog);
    }
}

void glCheckAndPrintProgramErrors(unsigned int program) {
    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM_LINK_FAILED\n%s\n", infoLog);
    }
}

const char *readFile(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("fopen");
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    char *buffer = malloc(size + 1);
    if (!buffer) {
        perror("malloc");
        fclose(f);
        return NULL;
    }

    size_t read = fread(buffer, 1, size, f);
    buffer[read] = '\0';

    fclose(f);
    return buffer;
}

unsigned int loadShader(const char *vertexShaderPath, GLenum type) {
    const char *shaderSource = readFile(vertexShaderPath);
    if (!shaderSource) return 0;

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    glCheckAndPrintShaderErrors(shader);
    free((char *)shaderSource);

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
