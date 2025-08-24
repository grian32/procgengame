//
// Created by grian on 8/23/25.
//

#include "Shader.h"

#include <iostream>
#include <ostream>

#include "../util.h"
#include "glm/common.hpp"
#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {
    std::string vertexCode = readFile(vertexPath);
    std::string fragmentCode = readFile(fragmentPath);

    const char* vertexCPtr = vertexCode.c_str();
    const char* fragmentCPtr = fragmentCode.c_str();

    int success;
    char infoLog[512];

    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertex, 1, &vertexCPtr, nullptr);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILE:\n" << infoLog << std::endl;
    }

    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragment, 1, &fragmentCPtr, nullptr);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILE:\n" << infoLog << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::LINK:\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() {
    glDeleteProgram(ID);
}

void Shader::use() const {
    glUseProgram(ID);
}

void Shader::setUniformMat4f(const std::string& name, glm::mat4 trans) const {
    GLint transformLoc = glGetUniformLocation(ID, name.c_str());
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

