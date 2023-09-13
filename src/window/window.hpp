#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../state/state.hpp"

class Window
{
  public:
    static GLFWwindow* CreateWindow(int width, int height, const char* title);
};