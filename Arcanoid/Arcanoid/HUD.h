#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class HUD : public Drawable
{
public:
	HUD();
	~HUD()=default;
	bool update(int& P, bool S);
	void nl(short lvl);

	void plus_hp();

	RectangleShape shape;
	Font czcionka;
	Text txt1;
	Text txt2;
	Texture tekstura1;
	Texture tekstura2;
	Texture tekstura3;
	Sprite s1;
	Sprite s2;
	Sprite s3;
	short hp;

private:
	void draw(RenderTarget& target, RenderStates state) const;
};

