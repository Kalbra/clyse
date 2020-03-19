#include <iostream>
#include <string>
#include <cstring>
#define GLEW_STATIC
#include <GL/glew.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "core.h"
#include <iostream>
#include <string>
#include <vector>
#include "/home/kalle/Programieren/c++ analytics/src/opengl/define_structure.h"
#include "/home/kalle/Programieren/c++ analytics/src/opengl/shader.h"
#include "/home/kalle/Programieren/c++ analytics/src/opengl/vertex_buffer.h"

using namespace std;


//Set and Add values
//Add item; include item into vetor array
void Diagram::AddItem(BarItem item){
  p_name.push_back(item.name);
  p_color.push_back(item.color);
  p_record.push_back(item.record);
}

//Set title; include title into vector array
void Diagram::SetTitle(string title){
  p_title = title;
}

//Set geometry; include x,y into vector array
void Diagram::SetGeometry(int x, int y){
  p_x = x;
  p_y = y;
}

/////////////////////////////////////


//Get values
//Get title
string Diagram::GetTitle(){
  return p_title;
}

//Get X geometry
int Diagram::GetXGeometry(){
  return p_x;
}

//Get X geometry
int Diagram::GetYGeometry(){
  return p_y;
}

int Diagram::Run(){
  /////////////////INITSTART/////////////////////
    p_count = p_record.size();

  	SDL_Window* window;
  	SDL_Init(SDL_INIT_EVERYTHING);

  	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

  	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

  	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  	window = SDL_CreateWindow(p_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_count*50, 400, SDL_WINDOW_OPENGL);

  	SDL_GLContext glContext = SDL_GL_CreateContext(window);

  	GLenum err = glewInit();



  	if(err != GLEW_OK){
  		cout << "errror";
      return -1;
  	}


  /////////////////INITEND///////////////////////

    for(int i = 0; i<p_count;i++){
      float window_graphic = (float)0.6f/(float)p_count;
      float window_graphic_space = (float)0.7f*(float)p_count;


      float shiftingx12 = (float)i /(float)window_graphic_space - (float)0.9f + (float)window_graphic;
      float shiftingx34 = (float)i /(float)window_graphic_space - (float)0.9f - (float)window_graphic;

      float shiftingy   = (float)p_record[i]*(float)18/(float)10 -(float)0.9f;

      float use_p_red_channel   = (((p_color[i] >> 16) & 0xFF) / 255.0);
      float use_p_green_channel = (((p_color[i] >> 8) & 0xFF) / 255.0);
      float use_p_blue_channel  = (((p_color[i]) & 0xFF) / 255.0);

      vertices.push_back(Vertex{shiftingx12,-0.9f, 0.0f,              use_p_red_channel, use_p_green_channel, use_p_blue_channel, 0.0f});
      vertices.push_back(Vertex{shiftingx12, 0.0f+shiftingy, 0.0f,    use_p_red_channel, use_p_green_channel, use_p_blue_channel, 0.0f});
      vertices.push_back(Vertex{shiftingx34,-0.9f, 0.0f,              use_p_red_channel, use_p_green_channel, use_p_blue_channel, 0.0f});
      vertices.push_back(Vertex{shiftingx34, 0.0f+shiftingy, 0.0f,    use_p_red_channel, use_p_green_channel, use_p_blue_channel, 0.0f});
    }

    int numberofvertices = vertices.size();

  VertexBuffer vertixBuffer(vertices.data(), numberofvertices);


  	Shader shader("src/opengl/shader/basic.vs", "src/opengl/shader/basic.fs");
  	shader.bind();

    uint64_t perfCounterFrequency = SDL_GetPerformanceFrequency();
    uint64_t lastCounter = SDL_GetPerformanceCounter();

    float delta = 0.0f;

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
      uint64_t endCounter = SDL_GetPerformanceCounter();
      uint64_t counterElapsed = endCounter - lastCounter;
      delta = ((float)counterElapsed / (float)perfCounterFrequency);
      uint32_t FPS = (uint32_t)((float)perfCounterFrequency / (float)counterElapsed);
      cout << FPS << endl;
      lastCounter = endCounter;
  	}
    return 0;
}
