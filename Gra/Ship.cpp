#include "pch.h"
#include "Ship.h"
#include "Bullet.h"
#include "iostream"
#include <vector>

using namespace std;

Ship::Ship(float x, float y, bool w)
{
	s.loadFromFile("ship.png");
	ship.setTexture(s);
	ship.setPosition(x, y);
	ship.setOrigin(size, size);
	if (w)
	{
		ship.setRotation(180);
	}
}

float Ship::left() {
	return this->ship.getPosition().x - size;
}

float Ship::right() {
	return this->ship.getPosition().x + size;
}

int Ship::getLife()
{
	return life;
}

void Ship::resetLife()
{
	life = 3;
}

void Ship::setCor(int x, int y)
{
	ship.setPosition(x, y);
}

Vector2f Ship::getCor()
{
	return Vector2f(ship.getPosition());
}

FloatRect Ship::getGB()
{
	return ship.getGlobalBounds();
}

void Ship::updatelife(bool l)
{
	
	if (l)
	{
		life++;
	}
	else if (!l)
	{
		life--;
	}
}



int Ship::update(int d,int &dealay)
{
	
	if ( d == 1 && (this->left() > 0) && dealay > 10)
	{
		velocity.x = -shipVelocity;
		ship.move(this->velocity);
		dealay = 0;
		return 1;
	}
	else if ( d == 10 && (this->right() < glength) && dealay > 10)
	{
		velocity.x = shipVelocity;
		ship.move(this->velocity);
		dealay = 0;
		return 2;
	}
	else {
		velocity.x = 0;
		return 0;
	}
	
}


int Ship::update(int& dealay)
{

	if (Keyboard::isKeyPressed(Keyboard::Key::A) && (this->left() > 0) && dealay > 10)
	{
		velocity.x = -shipVelocity;
		ship.move(this->velocity);
		dealay = 0;
		return 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D) && (this->right() < glength) && dealay > 10)
	{
		velocity.x = shipVelocity;
		ship.move(this->velocity);
		dealay = 0;
		return 2;
	}
	else {
		velocity.x = 0;
		return 0;
	}

}



void Ship::shot(vector <Bullet>& bullets, Bullet bullet, int& dealay,bool a)
{
	
	if ( a==1 && dealay > 100)
	{
		bullet.set(this->getCor());
		bullets.push_back(bullet);
		dealay = 0;
	}
}


void Ship::shot(vector <Bullet>& bullets, Bullet bullet, int& dealay)
{

	if (Keyboard::isKeyPressed(Keyboard::Space) && dealay > 20)
	{
		bullet.set(this->getCor());
		bullets.push_back(bullet);
		dealay = 0;
	}
}


void Ship::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->ship, state);
}
