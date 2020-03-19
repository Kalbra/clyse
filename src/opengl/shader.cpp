#include "shader.h"
#include <fstream>
#include <iostream>

Shader::Shader(const char* VertexShaderFileName, const char* FragmentShaderFileName){
  ShaderId = CreateShader(VertexShaderFileName, FragmentShaderFileName);
}

Shader::~Shader(){
  glDeleteProgram(ShaderId);
}

void Shader::bind(){
  glUseProgram(ShaderId);
}

void Shader::unbind(){
  glUseProgram(0);
}

GLuint Shader::givecode(std::string shadercode, GLenum type){
  GLuint id = glCreateShader(type);
  const char* src = shadercode.c_str();
  glShaderSource(id, 1, &src, 0);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);
  if(result != GL_TRUE){
    int length = 0;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    char* message = new char[length];
    glGetShaderInfoLog(id, length, &length, message);
    std::cout << "Shader compile errror: " << message << std::endl;
    delete[] message;
    return 0;
  }
  return id;
}

std::string Shader::parse(const char* FileName){
  FILE* file;
  file = fopen(FileName, "rb");
  if(file == nullptr){
    std::cout << "File not Found" << std::endl;
  }
  std::string content;
  fseek(file, 0, SEEK_END);
  size_t filesize = ftell(file);
  rewind(file);
  content.resize(filesize);
  fread(&content[0], 1, filesize, file);
  fclose(file);
  return content;

}

GLuint Shader::CreateShader(const char* VertexShaderFileName, const char* FragmentShaderFileName){
  std::string vertexShaderSource = parse(VertexShaderFileName);
  std::string fragmentShaderSource = parse(FragmentShaderFileName);

  GLuint program = glCreateProgram();
  GLuint vs = givecode(vertexShaderSource, GL_VERTEX_SHADER);
  GLuint fs = givecode(fragmentShaderSource, GL_FRAGMENT_SHADER);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);

  return program;
}
