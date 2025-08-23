//
// Created by grian on 8/22/25.
//

#ifndef PROC_GEN_GAME_UTIL_H
#define PROC_GEN_GAME_UTIL_H
#include <string>

#include "glad/glad.h"

void glClearColorRgb(int red, int green, int blue);
std::string readFile(const std::string& filename);
void glCheckAndPrintShaderErrors(unsigned int shader);
void glCheckAndPrintProgramErrors(unsigned int program);
unsigned int loadShader(const std::string& vertexShaderPath, GLenum type);
unsigned int loadProgram(unsigned int vertexShader, unsigned int fragmentShader);

#endif //PROC_GEN_GAME_UTIL_H