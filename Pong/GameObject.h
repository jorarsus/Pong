#pragma once

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

/*
	Abstract class to define the interface for all objects of the game
*/
class GameObject
{
public:
	GameObject(float x = 0.0, float y = 0.0);
	~GameObject();

	// Pure abstract methods that must be implemented when instantiating a derived class
	virtual void display(SDL_Renderer* renderer) =0;
	virtual void update() =0;
	virtual void handleEvent() =0;

	virtual void updateCollisionBox(float x, float y, float w, float h);
	SDL_Rect* collisionBox_;

protected:
	// position of the upper left corner of the object
	float x_pos_ = 0.0;
	float y_pos_ = 0.0;
	float x_speed_ = 0.0;
	float y_speed_ = 0.0;
};

