#include "window.hpp"

GLFWwindow *Window::CreateWindow(int width, int height, const char *title)
{
  // Initialize window manager library
  if(!glfwInit())
  {
    std::cout << "ERROR::GLFW::INIT" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Set OpenGL version and profile
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create window
  GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if(!window)
  {
    std::cout << "ERROR::GLFW::WINDOW" << std::endl;
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  // Load OpenGL functions
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "ERROR::GLAD::INIT" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Set the window initialized state for the classes that needs it
  state.isWindowInitialized = true;
  return window;
}