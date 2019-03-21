#pragma once
#include <SFML/Graphics.hpp>
#include "przycisk.h"
#include "HUD.h";

using namespace sf;
using namespace std;

class Menu : public Drawable
{
public:
	Menu();
	~Menu() = default;
	bool update(RenderWindow& window, HUD& hud, int& P);
	RectangleShape shape;
	Przycisk p1;
	Przycisk p2;
	Przycisk sp1;
	Przycisk sp2;
	Przycisk sp3;

	bool sklep;

private:
	void draw(RenderTarget& target, RenderStates state) const;
};