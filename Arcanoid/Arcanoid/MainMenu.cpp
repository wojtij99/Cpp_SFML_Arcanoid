#include "pch.h"
#include <iostream>
#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include "przycisk.h"
#include "Gra.h"

using namespace sf;
using namespace std;

MainMenu::MainMenu(RenderWindow& window, Event& event)
{
	//Twoøenie okbektÛw:
	//Twoøenie przyciskÛw:
	Przycisk p1(530, 300, 300, 60, 99, 99, 99, "NOWA GRA", "fonts/arial.ttf", 30);
	Przycisk p2(530, 370, 300, 60, 99, 99, 99, "WCZYTAJ GRE", "fonts/arial.ttf", 30);
	Przycisk p3(530, 440, 300, 60, 99, 99, 99, "OPCJE", "fonts/arial.ttf", 30);
	Przycisk p4(530, 510, 300, 60, 99, 99, 99, "WYJDè", "fonts/arial.ttf", 30);
	Przycisk op1 (530, 300, 300, 60, 99, 99, 99, "MAX FPS", "fonts/arial.ttf", 30);
	Przycisk op2 (530, 370, 300, 60, 99, 99, 99, "ZASTOSUJ I WR”∆", "fonts/arial.ttf", 30);

	Font czcionka;
	czcionka.loadFromFile("fonts/arial.ttf");
	Text txt1;
	txt1.setFont(czcionka);
	txt1.setCharacterSize(60);
	txt1.setPosition(860,290);
	txt1.setString("60");
	bool click1 = false;
	bool click2 = false;
	bool click3 = false;
	bool click4 = false;
	bool clicko1 = false;
	bool clicko2 = false;
	bool opcje = false;
	short w = 3;
	fstream plik;
	plik.open("opcje.set", ios::in);
	string linia;
	short nr_linii = 1;
	if (plik.good() == false) cout << "Nie mozna otworzyc pliku!";
	while (getline(plik, linia))
	{
		w = atoi(linia.c_str());
	}
	if (w == 1)
	{
		window.setFramerateLimit(20);
		cout << "MAX FPS = 20" << endl;
		txt1.setString("20");
	}
	else if (w == 2)
	{
		window.setFramerateLimit(30);
		cout << "MAX FPS = 30" << endl;
		txt1.setString("30");
	}
	else if (w == 3)
	{
		window.setFramerateLimit(60);
		cout << "MAX FPS = 60" << endl;
		txt1.setString("60");
	}
	plik.close();
	while (true)
	{
		window.clear(Color(0, 0, 0));
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}

		if (!opcje)
		{
			click1 = p1.update(window);
			click2 = p2.update(window);
			click3 = p3.update(window);
			click4 = p4.update(window);
			if (click1)
			{
				Gra gra(window, event, 0, 0, 3, w);
			}
			else if (click2)
			{
				int p = 0;
				short l = 0;
				short h = 3;
				fstream plik;
				plik.open("sav/sav.sav", ios::in);
				string linia;
				short nr_linii = 1;
				if (plik.good() == false) cout << "Nie mozna otworzyc pliku!";
				while (getline(plik, linia))
				{
					switch (nr_linii)
					{
					case 1: l = atoi(linia.c_str()); break;
					case 2: p = atoi(linia.c_str()); break;
					case 3: h = atoi(linia.c_str()); break;
					}
					nr_linii++;
				}
				Gra gra(window, event, p, l - 1, h, w);
			}
			else if (click3)
			{
				opcje = true;
			}
			else if (click4)
			{
				window.close();
				break;
			}
			window.draw(p1);
			window.draw(p2);
			window.draw(p3);
			window.draw(p4);
		}
		else
		{
			clicko1 = op1.update(window);
			clicko2 = op2.update(window);

			if (clicko1)
			{
				w++;
				if (w == 1)
				{
					window.setFramerateLimit(20);
					cout << "MAX FPS = 20" << endl;
					txt1.setString("20");
				}
				else if (w == 2)
				{
					window.setFramerateLimit(30);
					cout << "MAX FPS = 30" << endl;
					txt1.setString("30");
				}
				else if (w == 3)
				{
					window.setFramerateLimit(60);
					cout << "MAX FPS = 60" << endl;
					txt1.setString("60");
				}
				else if (w == 4)
				{
					w = 0;
					clicko1 = true;
				}
				clicko1 = false;
			}
			if (clicko2)
			{
				opcje = false;
				fstream plik;
				plik.open("opcje.set", ios::out);
				plik << w << endl;
				plik.close();
			}
			window.draw(op1);
			window.draw(op2);
			window.draw(txt1);
		}
		window.display();
	}
}