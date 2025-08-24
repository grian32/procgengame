//
// Created by grian on 8/24/25.
//

#ifndef PROC_GEN_GAME_TEXTURE_H
#define PROC_GEN_GAME_TEXTURE_H
#include <string>

#include "glad/glad.h"


class Texture {
public:
    GLuint ID;
    GLuint Unit;
    explicit Texture(const std::string& fileName);
    void bind() const;
};


#endif //PROC_GEN_GAME_TEXTURE_H