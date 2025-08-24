//
// Created by grian on 8/23/25.
//

#ifndef PROC_GEN_GAME_SHADER_H
#define PROC_GEN_GAME_SHADER_H
#include <string>

#include "glm/fwd.hpp"


class Shader {
public:
    unsigned int ID;
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
    void use() const;

    void setUniformMat4(const ::std::string &name, glm::mat4 trans) const;
};


#endif //PROC_GEN_GAME_SHADER_H