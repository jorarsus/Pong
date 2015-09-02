#pragma once
#include "GameObject.h"

class Paddle : public GameObject
{
public:
	Paddle(float x, float y);
	~Paddle();

	virtual void display(SDL_Renderer* renderer);
	virtual void update();
	virtual void handleEvent();

	const float length = 80.0;
	const float width = 20.0;
};