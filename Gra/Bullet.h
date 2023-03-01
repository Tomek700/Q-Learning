#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;



class Bullet : public Drawable
{
public:
	Bullet(bool x); 
	void update();
	void set(Vector2f cor);
	void setvelocity();
	Vector2f get();
	bool checkCollision(FloatRect x);
private:
	ConvexShape bullet;
	float bulletVelocity{ -50.f };
	Vector2f velocity{ 0,bulletVelocity };
	void draw(RenderTarget &target, RenderStates state) const override;

};
