#include "minimalgraph.h"

int main(int argc, char const *argv[]) {
	MiniGraph mygraph(1.0f, 1.0f);
	mygraph.add(1.0f,0.0f,0.0f,1.0f);
	mygraph.add(0.0f,1.0f,0.0f,0.3f);
	mygraph.add(0.0f,0.0f,1.0f,0.5f);
	mygraph.add(0.1f,1.0f,1.0f,0.1f);

	mygraph.run();

	return 0;
}
