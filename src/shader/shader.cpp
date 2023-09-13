#include "shader.hpp"

Shader::Shader(const char *vShaderData, const char *fShaderData)
{
  this->Compile(vShaderData, fShaderData);
}

void Shader::Compile(const char *vShaderData, const char *fShaderData)
{
  // Leave without doing nothing because opengl is not initialized
  if(!state.isWindowInitialized)
  {
    std::cout << "ERROR::SHADER::WINDOW_NOT_INITIALIZED" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Create, set data, compile and check errors on the vertex shader
  GLuint vShader, fShader;
  vShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vShader, 1, &vShaderData, NULL);
  glCompileShader(vShader);
  this->printErrors(vShader, "VERTEX");

  // Create, set data, compile and check errors on the fragment shader
  fShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fShader, 1, &fShaderData, NULL);
  glCompileShader(fShader);
  this->printErrors(fShader, "FRAGMENT");

  // Create, add shaders and link the shader program
  this->ID = glCreateProgram();
  glAttachShader(this->ID, vShader);
  glAttachShader(this->ID, fShader);
  glLinkProgram(this->ID);
  this->printErrors(this->ID, "PROGRAM");

  // Cleanup after everything is done
  glDeleteShader(vShader);
  glDeleteShader(fShader);
}

void Shader::Use()
{
  glUseProgram(this->ID);
}

void Shader::printErrors(GLuint id, const char* type)
{
  int success;
  char infoLog[1024];

  if(type == "PROGRAM")
  {
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if(!success)
    {
      glGetProgramInfoLog(id, sizeof(infoLog), NULL, infoLog);
      std::cout << "ERROR::SHADER::" << type << ": " << infoLog << std::endl;
    }
    return;
  }

  glGetShaderiv(id, GL_COMPILE_STATUS, &success);
  if(!success)
  {
    glGetShaderInfoLog(id, sizeof(infoLog), NULL, infoLog);
    std::cout << "ERROR::SHADER::" << type << ": " << infoLog << std::endl;
  }
}