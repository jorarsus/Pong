#pragma once

#include <SDL.h>
#include <iostream>
#include <list>

#include "GameObject.h"
#include "Paddle.h"
#include "Ball.h"
/*
	Class that defines the global state of the game
	Uses Singleton pattern (only 1 instance)
*/
class Pong
{
public:
	
	~Pong();

	void gameLoop();
	static Pong* instance();

	
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const float DESIRED_FPS = 60;

protected:
	Pong(); // Protected constructor for Singleton

private:
	static Pong* instance_;

	int setup();
	void processInput();
	void update();
	void display();

	

	SDL_Window* window_;
	SDL_Renderer* renderer_;
	std::list<GameObject*> gameObjectList_;
	bool initialized_ = false;
	bool quit_ = false;
};

