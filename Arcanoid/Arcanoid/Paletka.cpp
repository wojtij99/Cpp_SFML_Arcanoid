#include "pch.h"
#include "Paletka.h"


Paletka::Paletka(short w)
{
	paddleVelocity = w;
	shape.setPosition(630,710);
	shape.setSize({ 75,20 });
	shape.setFillColor(Color(133,133,133));
	shape.setOrigin(75/2.f, 20/2.f);
}

void Paletka::update()
{
	shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
	{
		velocity.x = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 1260)
	{
		velocity.x = paddleVelocity;
	}
	else
	{
		velocity.x = 0;
	}
}

void Paletka::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float Paletka::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Paletka::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Paletka::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Paletka::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Paletka::getPosition()
{
	return shape.getPosition();
}