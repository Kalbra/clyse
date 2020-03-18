#ifndef MINIMALGRAPH_H
#define MINIMALGRAPH_H

#include <vector>
#include <string>
#include "opengl/define_structure.h"
#include "analystic.h"

class MiniGraph {
public:
  MiniGraph(float from, float to);
  void add(float, float, float, float value);

  void title(std::string);
  void from(float from);
  void to(float to);


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

  std::string p_title = "MiniGraph";
};


#endif /* end of include guard: MINIMALGRAPH_H */
