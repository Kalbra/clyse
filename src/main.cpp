#include "core/core.h"

using namespace std;

int main() {

	BarItem Item1;                  //Add Item1
	Item1.color = 0x0000FF;         //Add color 0x0000FF
 	Item1.name  = "Untitled 1";     //Add name
	Item1.record = 0.2f;            //Add value from 0.0f to 1.0f

	BarItem Item2;
	Item2.color = 0x00FF00;
 	Item2.name  = "Untitled 2";
	Item2.record = 1.0f;

	BarItem Item3;
	Item3.color = 0xFF0000;
 	Item3.name  = "Untitled 1";
	Item3.record = 0.2f;

	BarItem Item4;
	Item4.color = 0xFFFF00;
 	Item4.name  = "Untitled 1";
	Item4.record = 1.0f;

	Diagram myDiagram;
	myDiagram.AddItem(Item1);
	myDiagram.AddItem(Item2);
	myDiagram.AddItem(Item3);



	myDiagram.SetGeometry(600, 800);

 	myDiagram.Run();

	return 0;
}
