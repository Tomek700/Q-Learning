#include "pch.h"
#include "Bohater.h"
using namespace sf;

Bohater::Bohater(float x, float y)
{
	B.setColor(sf::Color(0, 255, 255, 128));
	B.setPosition(x,y);
	B.setRotation(30.f);
	B.setOrigin(0, 0);
	B.setScale(2.f, 0.5f);
}

void Bohater::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->B, state);
}
