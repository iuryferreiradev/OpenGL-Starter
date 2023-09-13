#pragma once

#include <iostream>
#include <glad/glad.h>
#include "../state/state.hpp"

class Shader
{
  public:
    GLuint ID;
    Shader(){};
    Shader(const char* vShaderData, const char* fShaderData);
    void Compile(const char* vShaderData, const char* fShaderData);
    void Use();
  private:
    void printErrors(GLuint id, const char* type);
};