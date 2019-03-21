#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Przycisk : public Drawable
{
public:
	short r;
	short g;
	short b;

	Przycisk(float X = 0, float Y = 0, float W = 100, float H = 50, short R = 0, short G = 0, short B = 0, string N = "OK", string F = "fonts/arial.ttf", short S = 11, short RN = 255, short GN = 255, short BN = 255);
	//Przycisk() = delete;
	~Przycisk() = default;

	void build(float X = 0, float Y = 0, float W = 100, float H = 50, short R = 0, short G = 0, short B = 0, string N = "OK", string F = "fonts/arial.ttf", short S = 11, short RN = 255, short GN = 255, short BN = 255);

	RectangleShape przycisk;
	Font czcionka;
	Text txt;

	bool update(RenderWindow& window, short mod = 20, bool lock = false);
	float left();
	float right();
	float top();
	float bottom();
	Vector2f getPosition();
private:
	void draw(RenderTarget& target, RenderStates state) const;
};

class SPrzycisk : public Drawable
{
public:

	SPrzycisk(float X = 0, float Y = 0, float W = 100, float H = 50, string SO = "img/placeholder", bool ST = false, string N = "OK", string F = "fonts/arial.ttf", short S = 11, short RN = 255, short GN = 255, short BN = 255);
	//Przycisk() = delete;
	~SPrzycisk() = default;

	void build(float X = 0, float Y = 0, float W = 100, float H = 50, string SO = "img/placeholder", bool St = false, string N = "OK", string F = "fonts/arial.ttf", short S = 11, short RN = 255, short GN = 255, short BN = 255);

	Texture tekstura;
	Sprite przycisk;
	RectangleShape p;
	Font czcionka;
	Text txt;

	bool update(RenderWindow& window, bool lock = false);
	float left();
	float right();
	float top();
	float bottom();
	Vector2f getPosition();
private:
	void draw(RenderTarget& target, RenderStates state) const;
};