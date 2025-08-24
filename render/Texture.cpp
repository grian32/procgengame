//
// Created by grian on 8/24/25.
//

#include "Texture.h"

#include "stb_image.h"

GLuint currUnit = 0;

Texture::Texture(const std::string &fileName) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);

    unsigned int tex;

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    int maxUnits;
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxUnits);

    ID = tex;
    Unit = currUnit;
    currUnit = (currUnit + 1) % maxUnits;
}

void Texture::bind() const {
    glActiveTexture(GL_TEXTURE0 + Unit);
    glBindTexture(GL_TEXTURE_2D, ID);
}
