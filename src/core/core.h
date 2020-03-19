#ifndef CORE_H
#define CORE_H
#include <string>
#include <vector>
#include "/home/kalle/Programieren/c++ analytics/src/opengl/define_structure.h"


struct BarItem {
  std::string name;
  int color;
  float record;
};

class Diagram{
public:
  void AddItem(BarItem item);

  void SetTitle(std::string title);
  void SetGeometry(int x, int y);

  int GetFPS();
  std::string GetTitle();
  int GetXGeometry();
  int GetYGeometry();

  int Run();

private:
  std::string p_title;
  int p_x;
  int p_y;
  int p_count;

  std::vector<std::string> p_name;
  std::vector<int> p_color;
  std::vector<float> p_record;

  std::vector<Vertex> vertices;
};

#endif /* end of include guard: CORE_H */
