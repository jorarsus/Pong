#pragma once
#include "GameObject.h"

class Paddle : public GameObject
{
public:
	Paddle();
	~Paddle();

	virtual void display(SDL_Renderer* renderer);
	virtual void update();
	virtual void handleEvent();

};