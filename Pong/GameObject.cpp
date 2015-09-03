#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(float x, float y)
{
	x_pos_ = x;
	y_pos_ = y;
}


GameObject::~GameObject()
{
}


void GameObject::updateCollisionBox(float x, float y, float w, float h)
{
	// lazy initialization
	if (collisionBox_ == NULL)
		collisionBox_ = new SDL_Rect();

	collisionBox_->x = x;
	collisionBox_->y = y;
	collisionBox_->w = w;
	collisionBox_->h = h;
}
