#include <iostream>
#include <string>
#include <cstring>
#define GLEW_STATIC
#include <GL/glew.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "minimalgraph.h"

#include "opengl/vertex_buffer.h"
#include "opengl/define_structure.h"
#include "opengl/shader.h"


using namespace std;



MiniGraph::MiniGraph(int count, float from, float to)
{
/////////////////INITSTART/////////////////////
	SDL_Window* window;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_OPENGL);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	GLenum err = glewInit();

	if(err != GLEW_OK){
		cout << "errror";
	}
/////////////////INITEND///////////////////////


	Vertex vertices[] = {
		Vertex{-0.5f,-0.5f, 0.0f,    1.0f, 0.0f, 0.0f, 0.0f},
		Vertex{-0.5f, 0.5f, 0.0f,    0.0f, 1.0f, 0.0f, 0.0f},
		Vertex{ 0.5f,-0.5f, 0.0f,    0.0f, 0.0f, 1.0f, 0.0f},
	//	Vertex{-0.5f,-0.5f, 0.0f,    1.0f, 0.0f, 0.0f, 0.0f},
	//	Vertex{ 0.5f, 0.5f, 0.0f,    0.0f, 1.0f, 0.0f, 0.0f},
		Vertex{0.5f, 0.5f, 0.0f,      1.0f, 1.0f, 1.0f, 0.0f},
	};

unsigned numberofvertices = 4;

VertexBuffer vertixBuffer(vertices, numberofvertices);

	Shader shader("opengl/shader/basic.vs", "opengl/shader/basic.fs");
	shader.bind();


	bool close = false;

	while (!close) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		vertixBuffer.bind();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, numberofvertices);

		SDL_GL_SwapWindow(window);



		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				close = true;
			}
		}
	}

}
