#ifndef VERTEX_BUFFER
#define VERTEX_BUFFER
#include <GL/glew.h>
#include "define_structure.h"

struct VertexBuffer {
  VertexBuffer(void* data, unsigned int numberofvertices){
      glGenVertexArrays(1, &vao);
      glBindVertexArray(vao);


      glGenBuffers(1, &bufferid);
      glBindBuffer(GL_ARRAY_BUFFER, bufferid);
      glBufferData(GL_ARRAY_BUFFER, numberofvertices * sizeof(Vertex), data, GL_STATIC_DRAW);

      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), offsetof(struct Vertex, x));

      glEnableVertexAttribArray(1);
      glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(struct Vertex, red_channel));

      glBindVertexArray(0);
  }
  virtual ~VertexBuffer(){
      glDeleteBuffers(1, &bufferid);
  }

  void bind(){
      glBindVertexArray(vao);
  }
  void unbind(){
      glBindBuffer(GL_ARRAY_BUFFER, 0);
  }
private:
  GLuint bufferid;
  GLuint vao;

};


#endif /* end of include guard: VERTEX_BUFFER */
