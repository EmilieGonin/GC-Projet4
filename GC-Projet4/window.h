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
	bool loadMedia();
	void destroy();
	void closeWindow();
	bool draw();
	bool refreshRender();
	Window();
	~Window();

private:
	bool succes;
	//Screen dimension constants
	const int SCREEN_WIDTH = 600;
	const int SCREEN_HEIGHT = 600;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* surface;

};

