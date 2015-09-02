#pragma once

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

/*
	Abstract class to define the interface for all objects of the game
*/
class GameObject
{
public:
	GameObject();
	~GameObject();

	// Pure abstract methods that must be implemented when instantiating a derived class
	virtual void display(SDL_Renderer* renderer) =0;
	virtual void update() =0;
	virtual void handleEvent() =0;

protected:
	float x_pos_ = 0.0;
	float y_pos_ = 0.0;
	float x_speed_ = 0.0;
	float y_speed_ = 0.0;
};

