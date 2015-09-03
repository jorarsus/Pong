#include "stdafx.h"
#include "Paddle.h"

using namespace std;

Paddle::Paddle(float x, float y): GameObject(x,y)
{
	acceptsInputEvents_ = true;
}


Paddle::~Paddle()
{
}

void Paddle::display(SDL_Renderer* renderer)
{
	boxColor(
		renderer,
		x_pos_ - width_ / 2,
		y_pos_ - length_ / 2,
		x_pos_ + width_ / 2,
		y_pos_ + length_ / 2,
		0xFFFFFFFF
	);
}

void Paddle::update()
{
	Pong* pong = Pong::instance();
	int windowWidth = pong->SCREEN_WIDTH;
	int windowHeight = pong->SCREEN_HEIGHT;
	int zero = 0;
	float last_y_pos = y_pos_;

	// Update position
	y_pos_ += y_speed_ / pong->DESIRED_FPS;

	// Update collision box
	updateCollisionBox(
		x_pos_ - width_ / 2,
		y_pos_ - length_ / 2, 
		width_,
		length_
	);

	/*
		Check collisions
	*/
	if (SDL_IntersectRectAndLine(collisionBox_, &zero, &zero, &windowWidth, &zero)) // Top border
	{
		// restore last position
		y_pos_ = last_y_pos;
		y_speed_ = 0.0;
	}
	else if (SDL_IntersectRectAndLine(collisionBox_, &zero, &windowHeight, &windowWidth, &windowHeight)) // Bottom border
	{
		// restore last position
		y_pos_ = last_y_pos;
		y_speed_ = 0.0;
	}
}


void Paddle::handleKeyboardState(const Uint8 * state)
{
	if (state[SDL_SCANCODE_UP])
	{
		y_speed_ = -speed_;
	}
	else if (state[SDL_SCANCODE_DOWN])
	{
		y_speed_ = speed_;
	}
	else
	{
		y_speed_ = 0.0;
	}
}
