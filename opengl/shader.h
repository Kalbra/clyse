#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include "define_structure.h"
#include <string>

struct Shader {
  Shader(const char* VertexShaderFileName, const char* FragmentShaderFileName);
  virtual ~Shader();

  void bind();
  void unbind();

private:
  GLuint givecode(std::string shadercode, GLenum type);
  std::string parse(const char* FileName);
  GLuint CreateShader(const char* VertexShaderFileName, const char* FragmentShaderFileName);

  GLuint ShaderId;

};


#endif /* end of include guard: SHADER_H */
