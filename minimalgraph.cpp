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
  p_count = p_value.size();

	SDL_Window* window;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_count*100, 400, SDL_WINDOW_OPENGL);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	GLenum err = glewInit();

	if(err != GLEW_OK){
		cout << "errror";
    return -1;
	}


/////////////////INITEND///////////////////////
  float shiftingy = 0.3;
  float shiftingx = 0;


  for(int i = 0; i<p_count;i++){
    float shiftingx = (float)i /(float)2 - (float)0.5f;
    float shiftingy = (float)p_value[i]*(float)18/(float)10 -(float)0.9f;

     cout << "Y: : "<< shiftingy << endl;

    float use_p_red_channel = p_red_channel[i];
    float use_p_green_channel = p_green_channel[i];
    float use_p_blue_channel = p_blue_channel[i];

    vertices.push_back(Vertex{ 0.2f+shiftingx,-0.9f, 0.0f,              use_p_red_channel, use_p_green_channel, use_p_blue_channel, 0.0f});
    vertices.push_back(Vertex{ 0.2f+shiftingx, 0.0f+shiftingy, 0.0f,    use_p_red_channel, use_p_green_channel, use_p_blue_channel, 0.0f});
    vertices.push_back(Vertex{-0.2f+shiftingx,-0.9f, 0.0f,              use_p_red_channel, use_p_green_channel, use_p_blue_channel, 0.0f});
    vertices.push_back(Vertex{-0.2f+shiftingx, 0.0f+shiftingy, 0.0f,    use_p_red_channel, use_p_green_channel, use_p_blue_channel, 0.0f});
  }

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

    for(int i = 0; i<p_count; i++){
      glDrawArrays(GL_TRIANGLE_STRIP, i*4, 4);
    }



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
