#include "pch.h"
#include "Gra.h"
#include "Paletka.h"
#include <iostream>
#include <fstream>
#include "Pilka.h"
#include "Blok.h"
#include "HUD.h"
#include "przycisk.h"
#include "Menu.h"

template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

void nowy(vector<Blok>& bloki, HUD& hud, short& lvl)
{
	lvl++;
	hud.nl(lvl);
	short tab[22][15];
	unsigned blokX{ 22 }, blokY{ 15 };
	for (int i = 0; i < blokY; i++)
	{
		for (int j = 0; j < blokX; j++)
		{
			tab[j][i] = 0;
		}
	}
	string mapa = "lvl/l" + to_string(lvl) + ".lvl";
	fstream plik;
	plik.open(mapa.c_str(), ios::in);
	string linia;
	short nr_linii = 1;
	if (plik.good() == false) cout << "Nie mozna otworzyc pliku!";
	short j;
	short stat[13];
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
			case 1: j = atoi(linia.c_str()); break;
			case 2: stat[1] = atoi(linia.c_str()); break;
			case 3: stat[2] = atoi(linia.c_str()); break;
			case 4: stat[3] = atoi(linia.c_str()); break;
			case 5: stat[4] = atoi(linia.c_str()); break;
			case 6: stat[5] = atoi(linia.c_str()); break;
			case 7: stat[6] = atoi(linia.c_str()); break;
			case 8: stat[7] = atoi(linia.c_str()); break;
			case 9: stat[8] = atoi(linia.c_str()); break;
			case 10: stat[9] = atoi(linia.c_str()); break;
			case 11: stat[10] = atoi(linia.c_str()); break;
			case 12: stat[11] = atoi(linia.c_str()); break;
			case 13: stat[12] = atoi(linia.c_str()); break;
		}
		nr_linii++;
	}
	short r[105];
	short p = 0;
	for (short i = 0; i < stat[1]; i++) { r[i] = 1; }
	p = stat[1];
	for (short i = 0; i < stat[2]; i++) { r[i + p] = 2; }
	p = p + stat[2];
	for (short i = 0; i < stat[3]; i++) { r[i + p] = 3; }
	p = p + stat[3];
	for (short i = 0; i < stat[4]; i++) { r[i + p] = 4; }
	p = p + stat[4];
	for (short i = 0; i < stat[5]; i++) { r[i + p] = 5; }
	p = p + stat[5];
	for (short i = 0; i < stat[6]; i++) { r[i + p] = 6; }
	p = p + stat[6];
	for (short i = 0; i < stat[7]; i++) { r[i + p ] = 7;}
	p = p + stat[7];
	for (short i = 0; i < stat[8]; i++) { r[i + p] = 8; }
	p = p + stat[8];
	for (short i = 0; i < stat[9]; i++) { r[i + p] = 9; }
	p = p + stat[9];
	for (short i = 0; i < stat[10]; i++) { r[i + p] = 10; }
	p = p + stat[10];
	for (short i = 0; i < stat[11]; i++) { r[i + p] = 11; }
	p = p + stat[11];
	for (short i = 0; i < stat[12]; i++) { r[i + p] = 12; }
	while (j != 0)
	{
		short x = rand() % 22;
		short y = rand() % 15;
		short z = rand() % 100;
		if (tab[x][y] == 0)
		{
			tab[x][y] = 1;
			bloki.emplace_back((x + 1)*(50 + 5), (y + 2)*(20 + 3), r[z]);
			j--;
		}
	}
	plik.close();
}

bool testcol(Blok& blok, Pilka& pilka)
{
	if (!isIntersecting(blok, pilka)) return false;

	float overlapLeft{ pilka.right() - blok.left() };
	float overlapRight{ blok.right() - pilka.left() };
	float overlapTop{ pilka.bottom() - blok.top() };
	float overlapBottom{ blok.bottom() - pilka.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		ballFromLeft ? pilka.velocity.x = -pilka.ballVelocity : pilka.velocity.x = pilka.ballVelocity;
	}
	else
	{
		ballFromTop ? pilka.velocity.y = -pilka.ballVelocity : pilka.velocity.y = pilka.ballVelocity;
	}
}

void GameOver(int P, RenderWindow& window, Event& event)
{
	Font czcionka;
	Text txt1;
	Text txt2;
	Przycisk p1(350, 450, 500, 100, 99, 99, 99, "PRZEJD DO MENU", "fonts/arial.ttf", 50);
	czcionka.loadFromFile("fonts/arial.ttf");
	txt1.setFont(czcionka);
	txt1.setString("GAME OVER");
	txt1.setCharacterSize(200);
	txt1.setPosition(20, 105);
	txt1.setFillColor(Color(255, 0, 0));
	txt2.setFont(czcionka);
	txt2.setString(L"Zdoby³eœ: "+ to_string(P) + L" punktów. GRATULACJE!");
	txt2.setCharacterSize(40);
	txt2.setPosition(20, 350);
	txt2.setFillColor(Color(255, 255, 255));
	bool click = false;
	while (true)
	{
		window.clear(Color(0, 0, 0));
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		click = p1.update(window);
		if (click)
		{
			break;
		}
		window.draw(p1);
		window.draw(txt1);
		window.draw(txt2);
		window.display();
	}
}

void WIN(int P, RenderWindow& window, Event& event)
{
	Font czcionka;
	Text txt1;
	Text txt2;
	Przycisk p1(350, 450, 500, 100, 99, 99, 99, "PRZEJD DO MENU", "fonts/arial.ttf", 50);
	czcionka.loadFromFile("fonts/arial.ttf");
	txt1.setFont(czcionka);
	txt1.setString("  WYGRANA");
	txt1.setCharacterSize(200);
	txt1.setPosition(20, 105);
	txt1.setFillColor(Color(0, 255, 0));
	txt2.setFont(czcionka);
	txt2.setString(L"Zdoby³eœ: " + to_string(P) + L" punktów. GRATULACJE!");
	txt2.setCharacterSize(40);
	txt2.setPosition(20, 350);
	txt2.setFillColor(Color(255, 255, 255));
	bool click = false;
	while (true)
	{
		window.clear(Color(0, 0, 0));
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		click = p1.update(window);
		if (click)
		{
			break;
		}
		window.draw(p1);
		window.draw(txt1);
		window.draw(txt2);
		window.display();
	}
}

Gra::Gra(RenderWindow& window, Event& event, int p, short l, short h, short w)
{
	short pi;
	short pa;
	if (w == 1) { pi = 12; pa = 14; }
	else if (w == 2) { pi = 10; pa = 12; }
	else if (w == 3) { pi = 6; pa = 8; }
	//Two¿enie obiektów:
	Paletka paletka(pa);
	Pilka pilka(pi);
	HUD hud;
	Menu menu;
	SoundBuffer buffer;
	buffer.loadFromFile("sound/Sound.wav");
	Sound sound;
	sound.setBuffer(buffer);
	
	vector<Blok> bloki;
	bool tap = false;
	bool pap = true;
	punkty = p;
	lvl = l;
	hud.hp = h;
	nowy(bloki,hud, lvl);
	bool bmenu = false;
	bool dmenu = false;
	while (true)
	{
		//WIN(punkty, window, event);
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			fstream plik;
			plik.open("sav/sav.sav", ios::out);
			plik << lvl << endl;
			plik << punkty << endl;
			plik << hud.hp << endl;
			window.close();
			plik.close();
			break;
		}
		window.clear(Color(0, 0, 0));
		/*if (Keyboard::isKeyPressed(Keyboard::Key::Enter)&&pap)
		{
			lvl++;
			nowy(bloki, hud, lvl);
			tap = false;
			pap = false;
			paletka.shape.setPosition(630, 710);
			pilka.shape.setPosition(630, 670);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Num1) && !pap)
		{
			pap = true;
		}*/
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) 
		{
			if (!bmenu)
			{
				bmenu = true;
			}
			else
			{
				bmenu = false;
			}
			dmenu = true;
		}
		else
		{
			dmenu = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Space))tap = true;
		if (tap && !bmenu)
		{
			if (!tap) tap = true;
			short ile = 0;
			bool z = true;
			for (auto& blok : bloki)
			{
				if (testcol(blok, pilka))
				{
					sound.play();
					punkty = punkty + 100;
					if (blok.update())
					{
						bloki.erase(begin(bloki) + ile);
						z = false;
						break;
					}
				}
				ile++;
			}
			if (pilka.shape.getGlobalBounds().intersects(paletka.shape.getGlobalBounds()))
			{
				if (!hud.update(punkty, pilka.update(true, true)))
				{
					paletka.shape.setPosition(630, 710);
					pilka.shape.setPosition(630, 670);
					tap = false;
					if (hud.hp==0)
					{
						GameOver(punkty,window,event);
						break;
					}
				}
			}
			else
			{
				if (!hud.update(punkty, pilka.update(false, true)))
				{
					punkty = punkty - 1000;
					if (punkty < 0) punkty = 0;
					paletka.shape.setPosition(630, 710);
					pilka.shape.setPosition(630, 670);
					tap = false;
					if (hud.hp == 0)
					{
						GameOver(punkty, window, event);
						break;
					}
				}
			}
			paletka.update();
			if (bloki.size() == 0) 
			{
				if (lvl = 50)
				{
					WIN(punkty, window, event);
				}
				else
				{
					nowy(bloki, hud, lvl);
					tap = false;
					paletka.shape.setPosition(630, 710);
					pilka.shape.setPosition(630, 670);
				}
			}
		}
		window.draw(paletka);
		window.draw(pilka);
		window.draw(hud);
		for (auto& blok : bloki) window.draw(blok);
		if (bmenu) 
		{ 
			if (menu.update(window,hud,punkty)) 
			{ 
				fstream plik;
				plik.open("sav/sav.sav", ios::out);
				plik << lvl << endl;
				plik << punkty << endl;
				plik << hud.hp << endl;
				break;
			}
			window.draw(menu); 
		}
		window.display();
	}
}