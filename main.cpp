#include "minimalgraph.h"
#include "analystic.h"

int main(int argc, char const *argv[]) {
	MiniGraph mygraph(1.0f, 1.0f);
	mygraph.add(1.0f,1.0f,1.0f,1.0f);

	mygraph.title("hello");

	mygraph.run();

	return 0;
}
