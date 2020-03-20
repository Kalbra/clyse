#ifndef CORE_H
#define CORE_H
#include <string>
#include <vector>
#include "../opengl/define_structure.h"

#define DIAGRAM_MODE_BAR 0x0001




struct BarItem {
  std::string name;
  int color;
  float record;
};

class Diagram{
public:
  void AddItem(BarItem item);

  void SetMode(int mode);
  void SetTitle(std::string title);
  void SetGeometry(int x, int y);

  int GetFPS();
  std::string GetTitle();
  int GetXGeometry();
  int GetYGeometry();

  int Run();

private:
  float APTRPx(int ax);
  float APTRPy(int ay);


  std::string p_title = "Diagram";
  int p_x = 600;
  int p_y = 400;
  int p_count;
  int p_mode = 0x0001;

  std::vector<std::string> p_name;
  std::vector<int> p_color;
  std::vector<float> p_record;

  std::vector<Vertex> vertices;
};

#endif /* end of include guard: CORE_H */
