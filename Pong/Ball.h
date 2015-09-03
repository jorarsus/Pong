#pragma once
#include "GameObject.h"
#include "Pong.h"

class Ball : public GameObject
{
public:
	Ball(float x, float y);
	~Ball();

	virtual void display(SDL_Renderer* renderer);
	virtual void update();
	virtual void handleKeyboardState(const Uint8* keyboardState);

private:
	void checkCollisions();
	const float radius_ = 10;
};



