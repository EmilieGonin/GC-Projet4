#pragma once
#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

class Window
{
public:
	bool init();
	void destroy();
	int WindowEvent();
	bool homeView();
	bool view2();
	bool refreshRender(); 
	bool renderText(const std::string& font_path);
	Window();
	~Window();

	bool running;

private:
	bool succes;
	//Screen dimension constants
	const int WINDOW_WIDTH = 600;
	const int WINDOW_HEIGHT = 600;
	SDL_Window* window;
	SDL_Renderer* renderer;
	
};