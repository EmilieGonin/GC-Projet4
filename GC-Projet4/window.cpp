#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include"window.h"

using namespace std;


Window::Window()
{
	this->running = true;
	this->succes = true;
	this->window = NULL;
	this->renderer = NULL;
	this->surface = NULL;
}

Window::~Window(){}


bool Window::init() {


	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		this->window = SDL_CreateWindow("Une fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer
		if (this->window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		if (this->renderer == NULL)//gestion des erreurs
		{
			printf("Window couldn't be rendered! : %s", SDL_GetError());
			return EXIT_FAILURE;
		}
	}

	return this->succes;
}

bool Window::loadMedia() {
	return this->succes;
}

void Window::destroy() {

	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit(); // On quitte la SDL

	//Quit SDL subsystems
	SDL_Quit();
}

bool Window::draw() {

	SDL_RenderClear(this->renderer);
	SDL_SetRenderDrawColor(this->renderer, 200, 50, 100, 255);
	SDL_Rect rectangle{ 0,0,this->WINDOW_WIDTH/2,this->WINDOW_HEIGHT };
	SDL_RenderDrawRect(this->renderer, &rectangle);
	SDL_RenderFillRect(this->renderer, &rectangle);

	return this->succes;
}

int Window::WindowEvent() {
	SDL_Event event;
	int fullscreen = 0;
	while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
	{
		switch (event.type)
		{
		case SDL_QUIT: // Clic sur la croix
			this->running = false;
			break;
		case SDL_KEYUP: // Relâchement d'une touche
			if (event.key.keysym.sym == SDLK_f) // Touche f
			{
				// Alterne du mode plein écran au mode fenêtré
				if (fullscreen == 0)
				{
					fullscreen = 1;
					SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN);
				}
				else if (fullscreen == 1)
				{
					fullscreen = 0;
					SDL_SetWindowFullscreen(this->window, 0);
				}
			}
			break;
		}
	}
	return 0;

}



bool Window::refreshRender() {

	SDL_RenderPresent(this->renderer);

	return this->succes;

}



//int window() {
//
//
//
//
//	SDL_Event evnt;
//	bool quit = false;
//	while (SDL_PollEvent(&evnt) != 0) {
//
//		if (evnt.type == SDL_QUIT) {
//			quit = true;
//		}
//	}
//
//
//	// Destruction du renderer et de la fenêtre :
//
//
//	return 0;
//}