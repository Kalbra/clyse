#include "minimalgraph.h"

int main(int argc, char const *argv[]) {
	MiniGraph mygraph(1.0f, 1.0f);
	mygraph.add(1.0f,1.0f,1.0f,1.0f);
	mygraph.add(1.0f,1.0f,1.0f,1.0f);
	mygraph.add(1.0f,1.0f,1.0f,1.0f);
	mygraph.run();

	return 0;
}
