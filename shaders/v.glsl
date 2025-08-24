#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTexCoord;

out vec3 col;
out vec2 TexCoord;

mat3 rotateX(float angle) {
    float c = cos(angle);
    float s = sin(angle);

    return mat3(1, 0, 0,
            0, c, -s,
            0, s, c);
}

void main() {
    gl_Position = vec4(rotateX(200) * aPos, 1.0);
    col = aCol;
    TexCoord = aTexCoord;
}