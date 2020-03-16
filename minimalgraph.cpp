#include <iostream>
#include <string>
#include <cstring>
#define GLEW_STATIC
#include <GL/glew.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <vector>

#include "minimalgraph.h"

#include "opengl/vertex_buffer.h"
#include "opengl/define_structure.h"
#include "opengl/shader.h"


using namespace std;


MiniGraph::MiniGraph(float from, float to){
  p_from  = from;
  p_to    = to;
}

int MiniGraph::add(float red_channel, float green_channel, float blue_channel, float value){
  p_red_channel.push_back(red_channel);
  p_green_channel.push_back(green_channel);
  p_blue_channel.push_back(blue_channel);
  p_value.push_back(value);
}

int MiniGraph::run()
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

	window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_value.size()*100, 400, SDL_WINDOW_OPENGL);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	GLenum err = glewInit();

	if(err != GLEW_OK){
		cout << "errror";
    return -1;
	}
  p_count = p_value.size();

/////////////////INITEND///////////////////////
  float shiftingy = 0.9;

  for(int i = 0; i<p_count;i++){
    float shiftingx = (float)i /(float)10;
    cout << shiftingx << endl;
    cout << i << endl;
    vertices.push_back(Vertex{ 0.2f+shiftingx,-0.9f, 0.0f,              p_red_channel[i], p_green_channel[i], p_blue_channel[i], 0.0f});
    vertices.push_back(Vertex{ 0.2f+shiftingx, 0.0f+shiftingy, 0.0f,    p_red_channel[i], p_green_channel[i], p_blue_channel[i], 0.0f});
    vertices.push_back(Vertex{-0.2f+shiftingx,-0.9f, 0.0f,              p_red_channel[i], p_green_channel[i], p_blue_channel[i], 0.0f});
    vertices.push_back(Vertex{-0.2f+shiftingx, 0.0f+shiftingy, 0.0f,    p_red_channel[i], p_green_channel[i], p_blue_channel[i], 0.0f});
  }

/*
	Vertex vertices[4] = {
		Vertex{-0.05f+shiftingx,-0.9f, 0.0f,              0.0f, 0.0f, 1.0f, 0.0f}, //Vertex 1
		Vertex{-0.05f+shiftingx, 0.0f+shiftingy, 0.0f,    0.0f, 0.0f, 1.0f, 0.0f}, //Vertex 2
		Vertex{ 0.05f+shiftingx,-0.9f, 0.0f,              0.0f, 0.0f, 1.0f, 0.0f}, //Vertex 3
		Vertex{ 0.05f+shiftingx, 0.0f+shiftingy, 0.0f,    0.0f, 0.0f, 1.0f, 0.0f}, //Vertex 4
	};
  */




  int numberofvertices = vertices.size();

 cout << "SIZE: "<< numberofvertices << endl;

VertexBuffer vertixBuffer(vertices.data(), numberofvertices);

	Shader shader("opengl/shader/basic.vs", "opengl/shader/basic.fs");
	shader.bind();


	bool close = false;

	while (!close) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		vertixBuffer.bind();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 4, 10);
//    glDrawArrays(GL_TRIANGLE_STRIP, 12, 16);


		SDL_GL_SwapWindow(window);



		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				close = true;
			}
		}
	}
  return 0;
}
