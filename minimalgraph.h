#ifndef MINIMALGRAPH_H
#define MINIMALGRAPH_H

#include <vector>
#include "opengl/define_structure.h"

class MiniGraph {
public:
  MiniGraph(float from, float to);
  int add(float red_channel, float green_channel, float blue_channel, float value);
  int run();

private:
  std::vector<float> p_red_channel;
  std::vector<float> p_green_channel;
  std::vector<float> p_blue_channel;
  std::vector<float> p_value;

  std::vector<Vertex> vertices;

  int   p_count;
  float p_from;
  float p_to;
};


#endif /* end of include guard: MINIMALGRAPH_H */
