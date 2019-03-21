#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Paletka : public Drawable
{
public:
	Paletka(short w);
	Paletka() = delete;
	~Paletka() = default;
	void update();

	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	RectangleShape shape;

	float paddleVelocity{ 8.0f };
	Vector2f velocity{ paddleVelocity,0.f };
private:
	void draw(RenderTarget& target, RenderStates state) const;
};

