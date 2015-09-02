#include "stdafx.h"
#include "Paddle.h"


Paddle::Paddle(float x, float y): GameObject(x,y)
{
	
}


Paddle::~Paddle()
{
}

void Paddle::display(SDL_Renderer* renderer)
{
	boxColor(renderer,
		x_pos_ - width / 2,
		y_pos_ - length / 2,
		x_pos_ + width / 2,
		y_pos_ + length / 2,
		0xFFFFFFFF);
}

void Paddle::update()
{
}

void Paddle::handleEvent()
{
}
