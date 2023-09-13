#include <iostream>
#include "./shader/shader.hpp"
#include "./window/window.hpp"
#include "./file/file.hpp"

int main()
{
  // Initialize libs, create window and setup opengl
  GLFWwindow* window = Window::CreateWindow(1280, 720, "OpenGL Starter");

  // Load shaders from file
  std::string vShaderCode = File::Read("assets/shaders/template-vert.glsl");
  std::string fShaderCode = File::Read("assets/shaders/template-frag.glsl");

  const char* vShaderData = vShaderCode.c_str();
  const char* fShaderData = fShaderCode.c_str();

  Shader shader(vShaderData, fShaderData);

  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}