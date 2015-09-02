#include "stdafx.h"
#include "Ball.h"

// Passing arguments to the base class
Ball::Ball(float x, float y) : GameObject(x, y)
{
	//Testing movement
	x_speed_ = 1.0;
	y_speed_ = -2.0;
}


Ball::~Ball()
{
}

void Ball::display(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, x_pos_, y_pos_, radius_, 0xFFFFFFFF);
}

void Ball::update()
{	
	Pong* pong = Pong::instance();
	int windowWidth = pong->SCREEN_WIDTH;
	int windowHeight = pong->SCREEN_HEIGHT;
	int zero = 0;

	// Update ball position
	x_pos_ += x_speed_ / pong->DESIRED_FPS;
	y_pos_ += y_speed_ / pong->DESIRED_FPS;

	// Update collision box
	updateCollisionBox(x_pos_ - radius_, y_pos_ - radius_, 2 * radius_, 2 * radius_);


	// Check for collisions with borders
	// Top border
	if (SDL_IntersectRectAndLine(collisionBox_, &zero, &zero, &windowWidth, &zero))
	{
		y_speed_ = -y_speed_;
	}
	// Bottom border
	else if (SDL_IntersectRectAndLine(collisionBox_, &zero, &windowHeight, &windowWidth, &windowHeight))
	{
		y_speed_ = -y_speed_;
	}
	// Left border
	else if (SDL_IntersectRectAndLine(collisionBox_, &zero, &zero, &zero, &windowHeight))
	{
		x_speed_ = -x_speed_;
	}
	// right border
	else if (SDL_IntersectRectAndLine(collisionBox_, &windowWidth, &zero, &windowWidth, &windowHeight))
	{
		x_speed_ = -x_speed_;
	}

	// TODO: Check for collision with paddles
}

void Ball::handleEvent()
{
}


