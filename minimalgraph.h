#ifndef MINIMALGRAPH_H
#define MINIMALGRAPH_H

struct MiniGraph {
  MiniGraph(int count, float from, float to);
  int add(float red_channel, float green_channel, float blue_channel, float value);

private:
  float red_channel[1];
  float green_channel[1];
  float blue_channel[1];
  float value[1];
};


#endif /* end of include guard: MINIMALGRAPH_H */
