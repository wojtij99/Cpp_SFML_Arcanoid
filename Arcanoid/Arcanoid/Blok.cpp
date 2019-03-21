#include "pch.h"
#include "Blok.h"

Blok::Blok(short X, short Y, short LVLK)
{
	lvlk = LVLK;
	shape.setPosition(X, Y);
	shape.setSize({ 50,20 });
	shape.setOrigin(75 / 2.f, 20 / 2.f);
	if (LVLK == 1) shape.setFillColor(Color(127, 255, 0));
	else if (LVLK == 2) shape.setFillColor(Color(0, 255, 0));
	else if (LVLK == 3) shape.setFillColor(Color(0, 128, 0));
	else if (LVLK == 4) shape.setFillColor(Color(255, 255, 0));
	else if (LVLK == 5) shape.setFillColor(Color(200, 200, 0));
	else if (LVLK == 6) shape.setFillColor(Color(180, 180, 0));
	else if (LVLK == 7) shape.setFillColor(Color(255, 175, 0));
	else if (LVLK == 8) shape.setFillColor(Color(255, 140, 0));
	else if (LVLK == 9) shape.setFillColor(Color(255, 69, 0));
	else if (LVLK == 10) shape.setFillColor(Color(255, 0, 0));
	else if (LVLK == 11) shape.setFillColor(Color(150, 0, 0));
	else if (LVLK == 12) shape.setFillColor(Color(120, 0, 0));
}

bool Blok::update()
{
	lvlk--;
	if (lvlk == 0)
	{
		return true;
	}
	else
	{
		if (lvlk == 1) shape.setFillColor(Color(127, 255, 0));
		else if (lvlk == 2) shape.setFillColor(Color(0, 255, 0));
		else if (lvlk == 3) shape.setFillColor(Color(0, 128, 0));
		else if (lvlk == 4) shape.setFillColor(Color(255, 255, 0));
		else if (lvlk == 5) shape.setFillColor(Color(200, 200, 0));
		else if (lvlk == 6) shape.setFillColor(Color(180, 180, 0));
		else if (lvlk == 7) shape.setFillColor(Color(255, 175, 0));
		else if (lvlk == 8) shape.setFillColor(Color(255, 140, 0));
		else if (lvlk == 9) shape.setFillColor(Color(255, 69, 0));
		else if (lvlk == 10) shape.setFillColor(Color(255, 0, 0));
		else if (lvlk == 11) shape.setFillColor(Color(150, 0, 0));
		else if (lvlk == 12) shape.setFillColor(Color(120, 0, 0));

		return false;
	}
}

void Blok::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float Blok::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Blok::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Blok::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Blok::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Blok::getPosition()
{
	return shape.getPosition();
}