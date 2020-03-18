#include "minimalgraph.h"
#include "core/core.h"
#include <iostream>
#include "css_color.h"

using namespace std;

int main(int argc, char const *argv[]) {

	MiniGraph mygraph(1.0f, 1.0f);
	mygraph.add(CSS_COLOR_CornflowerBlue,1.0f);
	mygraph.title("hello");
	mygraph.run();

	return 0;
}
