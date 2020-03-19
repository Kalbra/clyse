#ifndef MINIMALGRAPH_H
#define MINIMALGRAPH_H

#include <vector>
#include <string>
#include "opengl/define_structure.h"
#include "core/core.h"

class MiniGraph {
public:
  MiniGraph(float from, float to);
  void add(int, float value);

  void title(std::string);
  void from(float from);
  void to(float to);

  void FRTAP(int x, int y, float *xa, float ya);


  int run();

private:
  std::vector<float> p_red_channel;
  std::vector<float> p_green_channel;
  std::vector<float> p_blue_channel;
  std::vector<float> p_value;

  std::vector<Vertex> vertices;

  int   p_count;

  float p_from = 0;
  float p_to   = 0;

  std::string p_title = "MiniGraph";
};


#endif /* end of include guard: MINIMALGRAPH_H */
