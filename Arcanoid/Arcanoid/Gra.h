#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Gra
{
public:
	Gra(RenderWindow& window, Event& event, int p, short l, short h,short w);
	Gra() = delete;
	~Gra() = default;

	int punkty;
	short lvl;
};

