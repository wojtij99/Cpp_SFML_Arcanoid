#include "pch.h"
#include "HUD.h"
#include <iostream>

HUD::HUD()
{
	hp = 3;
	shape.setPosition(0, 0);
	shape.setSize({ 1260,30 });
	shape.setFillColor(Color(160, 160, 160));
	czcionka.loadFromFile("fonts/arial.ttf");
	txt1.setFont(czcionka);
	txt2.setFont(czcionka);
	txt1.setCharacterSize(15);
	txt2.setCharacterSize(15);
	txt1.setString(L"LEVEL:1/50");
	txt2.setString(L"SCORE:0");
	txt1.setPosition(5,5);
	txt2.setPosition(110,5);
	tekstura1.loadFromFile("img/serce.png");
	tekstura2.loadFromFile("img/serce.png");
	tekstura3.loadFromFile("img/serce.png");
	s1.setTexture(tekstura1, true);
	s1.setPosition(1238,5);
	s2.setTexture(tekstura2, true);
	s2.setPosition(1216,5);
	s3.setTexture(tekstura3, true);
	s3.setPosition(1194,5);
	if (hp == 1)
	{
		tekstura2.loadFromFile("img/serce_d.png");
		tekstura3.loadFromFile("img/serce_d.png");
		s2.setTexture(tekstura2, true);
		s3.setTexture(tekstura3, true);
	}
	else if (hp == 2)
	{
		tekstura3.loadFromFile("img/serce_d.png");
		s3.setTexture(tekstura3, true);
	}
}

bool HUD::update(int& P,bool S)
{
	if (!S)
	{
		if (hp != 0)
		{
			if (hp == 1)
			{
				tekstura1.loadFromFile("img/serce_d.png");
				s1.setTexture(tekstura1, true);
				s2.setTexture(tekstura1, true);
				s3.setTexture(tekstura1, true);
			}
			else if (hp == 2)
			{
				tekstura2.loadFromFile("img/serce_d.png");
				s2.setTexture(tekstura2, true);
				s3.setTexture(tekstura2, true);
			}
			else if (hp == 3)
			{
				tekstura3.loadFromFile("img/serce_d.png");
				s3.setTexture(tekstura3, true);
			}
			hp--;
			string punkty = to_string(P);
			txt2.setString(L"SCORE: " + punkty);
			return false;
		}
	}
	else
	{
		string punkty = to_string(P);
		txt2.setString(L"SCORE: " + punkty);
		return true;
	}
}

void HUD::nl(short lvl)
{
	txt1.setString(L"LEVEL: " + to_string(lvl) + " / 50");
}

void HUD::plus_hp()
{
	hp++;
	if (hp == 1)
	{
		tekstura1.loadFromFile("img/serce.png");
		s1.setTexture(tekstura1, true);
		s2.setTexture(tekstura1, true);
	}
	else if (hp == 2)
	{
		tekstura3.loadFromFile("img/serce.png");
		s2.setTexture(tekstura3, true);
		s3.setTexture(tekstura3, true);
	}
}

void HUD::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
	target.draw(this->txt1, state);
	target.draw(this->txt2, state);
	target.draw(this->s1, state);
	target.draw(this->s2, state);
	target.draw(this->s3, state);
}