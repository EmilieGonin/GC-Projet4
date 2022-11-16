#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include"window.h"



Window::Window()
{
	bool succes = true;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* surface = NULL;
}

Window::~Window()
{
}


bool Window::init() {



	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Une fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		if (renderer == NULL)//gestion des erreurs
		{
			printf("Window couldn't be rendered! : %s", SDL_GetError());
			return EXIT_FAILURE;
		}
	}

	return succes;
}

bool Window::loadMedia() {
	return succes;
}

void Window::destroy() {
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit(); // On quitte la SDL

	//Quit SDL subsystems
	SDL_Quit();
}

bool Window::draw() {

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 200, 50, 100, 255);
	SDL_Rect rectangle{ 0,0,300,300 };
	SDL_RenderDrawRect(renderer, &rectangle);
	SDL_RenderFillRect(renderer, &rectangle);

	return succes;
}

void Window::closeWindow() {

	SDL_Event evnt;
	bool quit = false;
	while (SDL_PollEvent(&evnt) != 0) {

		if (evnt.type == SDL_QUIT) {
			quit = true;
		}
	}

}


bool Window::refreshRender() {

	SDL_RenderPresent(renderer);

}

	

int window() {


	

	SDL_Event evnt;
	bool quit = false;
	while (SDL_PollEvent(&evnt) != 0) {

		if (evnt.type == SDL_QUIT) {
			quit = true;
		}
	}


	// Destruction du renderer et de la fenêtre :
	

	return 0;
}