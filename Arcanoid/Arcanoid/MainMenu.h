#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class MainMenu
{
public:
	MainMenu(RenderWindow& window, Event& event);
	MainMenu() = delete;
	~MainMenu() = default;
};

