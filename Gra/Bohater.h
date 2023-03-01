#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Bohater : public Drawable
{
public:
	Bohater(float x, float y);
	Bohater()=delete;
	~Bohater()=default;

private:
	Sprite B;
	const float valecity{ 1.0f };
	void draw(RenderTarget &target, RenderStates state) const override;

};

