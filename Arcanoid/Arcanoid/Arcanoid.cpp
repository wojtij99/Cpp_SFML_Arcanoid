#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MainMenu.h"

using namespace sf;
using namespace std;

int main()
{
	srand(time(NULL));
	RenderWindow window{ VideoMode{1260,760}, "Arcanoid" };
	window.setFramerateLimit(60);
	Event event;
	MainMenu Mm(window, event);
}