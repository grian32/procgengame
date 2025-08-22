//
// Created by grian on 8/22/25.
//
#include <GL/gl.h>


void glClearColorRgb(int red, int green, int blue) {
    glClearColor((float)red/255, (float)green/255, (float)blue/255, 1.0f);
}