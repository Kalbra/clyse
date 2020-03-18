#include "minimalgraph.h"
#include "core/core.h"
#include <iostream>

RGB_color color;

using namespace std;

int main(int argc, char const *argv[]) {
	color.r = 1.0f;
	color.g = 0.0f;
	color.b = 1.0f;
	MiniGraph mygraph(1.0f, 1.0f);
	mygraph.add(color,1.0f);
	mygraph.title("hello");
	mygraph.run();


	return 0;
}
