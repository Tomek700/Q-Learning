#include "pch.h"
#include "Bullet.h"
#include "iostream"
using namespace std;

Bullet::Bullet(bool x)
{
	bullet.setPointCount(5);
	bullet.setPoint(0, Vector2f(0.f, 0.f));
	bullet.setPoint(1, Vector2f(5.f, 0.f));
	bullet.setPoint(2, Vector2f(5.f, 7.f));
	bullet.setPoint(3, Vector2f(2.5f, 10.f));
	bullet.setPoint(4, Vector2f(0.f, 7.f));
	if (x)
	{
		bullet.setRotation(180);
	}
	if (!x) {
		setvelocity();
	}
	
	bullet.setFillColor(Color::Red);
	bullet.setOutlineColor(Color::Color(150,75,0));
}

void Bullet::update()
{
	bullet.move(velocity);
}

void Bullet::set(Vector2f cor)
{
	bullet.setPosition(cor);
}

void Bullet::setvelocity()
{
	velocity=-velocity;
}

Vector2f Bullet::get()
{
	return Vector2f(bullet.getPosition());
}

bool Bullet::checkCollision(FloatRect x)
{
	return bullet.getGlobalBounds().intersects(x);
}

void Bullet::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->bullet, state);
}
