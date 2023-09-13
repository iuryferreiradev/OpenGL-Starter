#include "file.hpp"

std::string File::Read(const char *path)
{
  std::string contents;
  try
  {
    std::filesystem::path filePath(path);
    if(!std::filesystem::exists(filePath) || !std::filesystem::is_regular_file(filePath))
    {
      std::cout << "ERROR::FILE::NOT_FOUND: " << path << std::endl;
      return contents;
    }

    std::ifstream file(filePath);
    if(!file.is_open())
    {
      std::cout << "ERROR::FILE::COULD_NOT_OPEN: " << path << std::endl;
      return contents;
    }

    std::ostringstream sstream;

    sstream << file.rdbuf();
    contents = sstream.str();
  }
  catch(const std::exception& e)
  {
    std::cerr << "ERROR::FILE: " << e.what() << std::endl;
  }
  return contents;
}