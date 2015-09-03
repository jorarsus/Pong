#pragma once
#include "GameObject.h"
#include "Pong.h"

class Paddle : public GameObject
{
public:
	Paddle(float x, float y);
	~Paddle();

	virtual void display(SDL_Renderer* renderer);
	virtual void update();
	virtual void handleKeyboardState(const Uint8* state);

private:
	const float length_ = 80.0;
	const float width_ = 20.0;
	const float speed_ = 2.0;
};