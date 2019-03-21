#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Blok : public Drawable
{
public:
	Blok(short X, short Y, short LVLK);
	Blok() = delete;
	~Blok() = default;
	bool update();
	RectangleShape shape;
	short lvlk=1;

	Vector2f getPosition();
	float left();
	float right();
	float top();
	float bottom();
private:
	void draw(RenderTarget& target, RenderStates state) const;
};

