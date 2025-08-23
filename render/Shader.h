//
// Created by grian on 8/23/25.
//

#ifndef PROC_GEN_GAME_SHADER_H
#define PROC_GEN_GAME_SHADER_H
#include <string>

class Shader {
public:
    unsigned int ID;
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
    void use() const;
};


#endif //PROC_GEN_GAME_SHADER_H