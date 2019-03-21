#include "pch.h"
#include "przycisk.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

//===============================================PRZYCISK====================================================

Przycisk::Przycisk(float X, float Y, float W, float H, short R, short G, short B, string N, string F, short S, short RN, short GN, short BN)
{
	r = R;
	g = G;
	b = B;
	przycisk.setPosition(X + W / 2.f, Y + H / 2.f);
	przycisk.setSize({ W, H });
	przycisk.setFillColor(Color(R, G, B));
	przycisk.setOrigin(W / 2.f, H / 2.f);
	czcionka.loadFromFile(F);
	txt.setFont(czcionka);
	locale loc(".1250"); // strona kodowa 'str'
	auto &cctv = use_facet<codecvt<wchar_t, char, mbstate_t>>(loc);
	wstring_convert<codecvt<wchar_t, char, mbstate_t>> converter(&cctv);
	wstring n = converter.from_bytes(N);
	txt.setString(n);
	txt.setCharacterSize(S);
	txt.setFillColor(Color(RN, GN, BN));
	txt.setPosition(X + W / 2.f - txt.getLocalBounds().width/2, Y + H / 2.f - txt.getLocalBounds().height);
}

void Przycisk::build(float X, float Y, float W, float H, short R, short G, short B, string N, string F, short S, short RN, short GN, short BN)
{
	r = R;
	g = G;
	b = B;
	przycisk.setPosition(X + W / 2.f, Y + H / 2.f);
	przycisk.setSize({ W, H });
	przycisk.setFillColor(Color(R, G, B));
	przycisk.setOrigin(W / 2.f, H / 2.f);
	czcionka.loadFromFile(F);
	txt.setFont(czcionka);
	locale loc(".1250"); // strona kodowa 'str'
	auto &cctv = use_facet<codecvt<wchar_t, char, mbstate_t>>(loc);
	wstring_convert<codecvt<wchar_t, char, mbstate_t>> converter(&cctv);
	wstring n = converter.from_bytes(N);
	txt.setString(n);
	txt.setCharacterSize(S);
	txt.setFillColor(Color(RN, GN, BN));
	txt.setPosition(X + W / 2.f - txt.getLocalBounds().width / 2, Y + H / 2.f - txt.getLocalBounds().height);
}

bool Przycisk::update(RenderWindow& window, short mod, bool lock)
{
	if (!lock)
	{
		if (Mouse::getPosition(window).x >= this->left() && Mouse::getPosition(window).x <= this->right() && Mouse::getPosition(window).y >= this->top() && Mouse::getPosition(window).y <= this->bottom())
		{
			short R1 = r;
			short B1 = b;
			short G1 = g;
			if (R1 <= 127)
			{
				R1 = R1 + mod;
			}
			else
			{
				R1 = R1 - mod;
			}
			if (G1 <= 127)
			{
				G1 = G1 + mod;
			}
			else
			{
				G1 = G1 - mod;
			}
			if (B1 <= 127)
			{
				B1 = B1 + mod;
			}
			else
			{
				B1 = B1 - mod;
			}
			this->przycisk.setFillColor(Color(R1, G1, B1));
			if (Mouse::isButtonPressed(sf::Mouse::Left))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			this->przycisk.setFillColor(Color(r, g, b));
			return false;
		}
	}
	else
	{
		return false;
	}
}

void Przycisk::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->przycisk, state);
	target.draw(this->txt, state);
}

float Przycisk::left()
{
	return this->przycisk.getPosition().x - przycisk.getSize().x / 2.f;
}

float Przycisk::right()
{
	return this->przycisk.getPosition().x + przycisk.getSize().x / 2.f;
}

float Przycisk::top()
{
	return this->przycisk.getPosition().y - przycisk.getSize().y / 2.f;
}

float Przycisk::bottom()
{
	return this->przycisk.getPosition().y + przycisk.getSize().y / 2.f;
}

Vector2f Przycisk::getPosition()
{
	return przycisk.getPosition();
}

//===============================================SPRZYCISK===================================================

SPrzycisk::SPrzycisk(float X, float Y, float W, float H, string SO, bool ST, string N, string F, short S, short RN, short GN, short BN)
{
	przycisk.setPosition(X + W / 2.f, Y + H / 2.f);
	p.setPosition(X + W / 2.f, Y + H / 2.f);
	przycisk.setOrigin(W / 2.f, H / 2.f);
	p.setOrigin(W / 2.f, H / 2.f);
	p.setSize({ W, H });
	tekstura.loadFromFile(SO);
	przycisk.setTexture(tekstura, true);
	if (ST)
	{
		czcionka.loadFromFile(F);
		txt.setFont(czcionka);
		locale loc(".1250"); // strona kodowa 'str'
		auto &cctv = use_facet<codecvt<wchar_t, char, mbstate_t>>(loc);
		wstring_convert<codecvt<wchar_t, char, mbstate_t>> converter(&cctv);
		wstring n = converter.from_bytes(N);
		txt.setString(n);
		txt.setCharacterSize(S);
		txt.setFillColor(Color(RN, GN, BN));
		txt.setPosition(X + W / 2.f - txt.getLocalBounds().width / 2, Y + H / 2.f - txt.getLocalBounds().height);
	}
}

void SPrzycisk::build(float X, float Y, float W, float H, string SO, bool ST, string N, string F, short S, short RN, short GN, short BN)
{
	przycisk.setPosition(X + W / 2.f, Y + H / 2.f);
	p.setPosition(X + W / 2.f, Y + H / 2.f);
	przycisk.setOrigin(W / 2.f, H / 2.f);
	p.setOrigin(W / 2.f, H / 2.f);
	p.setSize({ W, H });
	tekstura.loadFromFile(SO);
	przycisk.setTexture(tekstura, true);
	if (ST)
	{
		czcionka.loadFromFile(F);
		txt.setFont(czcionka);
		txt.setString(N);
		txt.setCharacterSize(S);
		txt.setFillColor(Color(RN, GN, BN));
		txt.setPosition(X + W / 2.f - txt.getLocalBounds().width / 2, Y + H / 2.f - txt.getLocalBounds().height);
	}
}

bool SPrzycisk::update(RenderWindow& window, bool lock)
{
	if (!lock)
	{
		if (Mouse::getPosition(window).x >= this->left() && Mouse::getPosition(window).x <= this->right() && Mouse::getPosition(window).y >= this->top() && Mouse::getPosition(window).y <= this->bottom())
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void SPrzycisk::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->przycisk, state);
	target.draw(this->txt, state);
}

float SPrzycisk::left()
{
	return this->p.getPosition().x - p.getSize().x / 2.f;
}

float SPrzycisk::right()
{
	return this->p.getPosition().x + p.getSize().x / 2.f;
}

float SPrzycisk::top()
{
	return this->p.getPosition().y - p.getSize().y / 2.f;
}

float SPrzycisk::bottom()
{
	return this->p.getPosition().y + p.getSize().y / 2.f;
}

Vector2f SPrzycisk::getPosition()
{
	return p.getPosition();
}