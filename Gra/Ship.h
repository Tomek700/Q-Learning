#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"
#include "Def.h"
using namespace sf;
using namespace std;

class Ship : public Drawable
{
public:
	Ship() = delete;
	Ship(float x, float y,bool w);
	int update(int d, int &dealay);
	int update(int& dealay);
	void shot(vector<Bullet>& bullets, Bullet bullet, int& dealay,bool a);
	void shot(vector <Bullet>& bullets, Bullet bullet, int& dealay);
	float left();
	float right();
	int getLife();
	void resetLife();
	void setCor(int x, int y);
	Vector2f getCor();
	FloatRect getGB();
	void updatelife(bool x);
	//-------------------
private:
	Texture s;
	Sprite ship;
	const size_t size{ 40 };
	float shipVelocity{ 80.0f };
	Vector2f velocity{ shipVelocity,0 };
	size_t life{ 3 };
	void draw(RenderTarget& target, RenderStates state) const override;
};

