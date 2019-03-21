#include "pch.h"
#include "Pilka.h"
#include "Blok.h"

Pilka::Pilka(short w)
{
	ballVelocity = w;
	shape.setPosition(630, 670);
	shape.setRadius(10);
	shape.setFillColor(Color(255,255,255));
	shape.setOrigin(10, 10);
}

bool Pilka::update(bool col, bool col2)
{
	shape.move(this->velocity);
	if (this->left() < 0)
	{
		velocity.x = ballVelocity;
	}
	else if (this->right() > 1260)
	{
		velocity.x = -ballVelocity;
	}

	if (this->top() < 30)
	{
		velocity.y = ballVelocity;
	}
	else if (this->bottom() > 760)
	{
		velocity.y = -ballVelocity;
		return false;
	}

	if (col && col2)
	{
		velocity.y = -ballVelocity;
	}
	return true;
}

void Pilka::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float Pilka::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Pilka::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Pilka::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Pilka::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

Vector2f Pilka::getPosition()
{
	return shape.getPosition();
}