#include "pch.h"
#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	sklep = false;
	shape.setPosition(500, 50);
	shape.setFillColor(Color(50, 50, 50));
	shape.setSize({ 300,650 });
	p1.build(550, 150, 200, 50, 100, 100, 100, "SKLEP","fonts/arial.ttf",30);
	p2.build(550, 225, 200, 50, 100, 100, 100, "WYJDè","fonts/arial.ttf",30);
	sp1.build(525, 150, 250, 50, 100, 100, 100, "KUP ØYCIE KOSZT:10000", "fonts/arial.ttf", 18);
	//sp2.build(525, 225, 250, 50, 100, 100, 100, "KUP POCISK KOSZT:10000", "fonts/arial.ttf", 18);
	sp3.build(525, 300, 250, 50, 100, 100, 100, "WR”∆", "fonts/arial.ttf", 30);
}

bool Menu::update(RenderWindow& window, HUD& hud, int& P)
{
	bool click1 = false;
	bool click2 = false;
	bool clicks1 = false;
	//bool clicks2 = false;
	bool clicks3 = false;
	if (!sklep)
	{
		click1 = p1.update(window);
		click2 = p2.update(window);
	}
	else
	{
		if (hud.hp == 3 || P < 10000)
		{
			clicks1 = false;
		}
		else
		{
			clicks1 = sp1.update(window);
		}
		/*if (P < 10000)
		{
			clicks2 = false;
		}
		else
		{
			clicks2 = sp2.update(window);
		}*/
		clicks3 = sp3.update(window);
	}
	if (click1)
	{
		sklep = true;
		return false;
	}
	else if (click2)
	{
		return true;
	}
	else if (sklep)
	{
		if (clicks1)
		{
			hud.plus_hp();
			P = P - 10000;
			return false;
		}
		//else if (clicks2)
		//{
		//	return false;
		//}
		else if (clicks3)
		{
			sklep = false;
			//cout << "click" << endl;
			return false;
		}
	}
	return false;
}

void Menu::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
	if (sklep)
	{
		target.draw(this->sp1, state);
		target.draw(this->sp2, state);
		target.draw(this->sp3, state);
	}
	else
	{
		target.draw(this->p1, state);
		target.draw(this->p2, state);
	}
}