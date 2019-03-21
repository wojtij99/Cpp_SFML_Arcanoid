#pragma once
#include <SFML/Graphics.hpp>
#include "Blok.h"

using namespace sf;
using namespace std;

class Pilka : public Drawable
{
public:
	Pilka(short w);
	Pilka() = delete;
	~Pilka() = default;
	bool update(bool col, bool col2);
	CircleShape shape;

	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	float ballVelocity{ 6.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
private:
	void draw(RenderTarget& target, RenderStates state) const;
};

