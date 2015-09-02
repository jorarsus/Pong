#include "stdafx.h"
#include "Ball.h"

// @TODO: Member initialization does not work here?
Ball::Ball(float x, float y)
{
	x_pos_ = x;
	y_pos_ = y;

	//Testing movement
	x_speed_ = 1.0;
	y_speed_ = -2.0;
}


Ball::~Ball()
{
}

void Ball::display(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, x_pos_, y_pos_, size_, 0xFFFFFFFF);
}

void Ball::update()
{
	Pong* pong = Pong::instance();

	// @TODO: change fps to float
	x_pos_ += x_speed_ / pong->DESIRED_FPS;
	y_pos_ += y_speed_ / pong->DESIRED_FPS;
}

void Ball::handleEvent()
{
}


