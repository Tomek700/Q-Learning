// Gra.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Ship.h"
#include "Bullet.h"
#include "Computer.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "Windows.h"

using namespace std;
using namespace sf;


int main()
 {
	//window
	RenderWindow w{ VideoMode{glength,gwidth},"Game" };
	w.setFramerateLimit(60);
	srand(unsigned int(time(NULL)));
	
	//variables
	int dealaymove = 0;
	int computerdealay = 0;
	int dealaybullets =0 ;
	int computerdealaybullets = 0;
	int pause = 0;
	int playermove = 0;
	int computermove = 0;
	int computermovedealay = 0;
	int s1 = 0, s2 = 0;
	String tex1,tex2,tex3,tex4,text1,text2,text3,text4,lives1,lives2;

	//Events,Texts,Texture service
	Event e;
	Texture texture;
	texture.loadFromFile("bac.png");
	texture.setRepeated(true);
	Sprite sprite(texture);
	sprite.setTextureRect(IntRect(0, 0, glength, gwidth));
	Font font;
	font.loadFromFile("arial.ttf");
	Text t,t1,playerlife,computerlife,score1,score2;

	score1.setFont(font);
	score2.setFont(font);
	t.setFont(font);
	t1.setFont(font);
	tex1 = "Player\n lives -  ";
	tex2 = "Computer\n lives -  ";
	tex3 = "Computer \n score :";
	tex4 = "Player \n score :";
	playerlife.setFont(font);
	computerlife.setFont(font);
	playerlife.setPosition(700,880);
	score2.setPosition(703, 830);
	computerlife.setPosition(700, 50);
	score1.setPosition(705, 100);
	playerlife.setCharacterSize(20);
	computerlife.setCharacterSize(20);
	score1.setCharacterSize(15);
	score2.setCharacterSize(15);
	score1.setFillColor(Color::Cyan);
	computerlife.setFillColor(Color::Cyan);
	playerlife.setFillColor(Color::Green);
	score2.setFillColor(Color::Green);
	t.setString("Player won!");
	t1.setString("Computer won!");
	t.setOutlineThickness(20);
	t1.setOutlineThickness(20);
	t.setCharacterSize(30);
	t.setFillColor(Color::Red);
	t.setPosition(350, 400);
	t1.setCharacterSize(30);
	t1.setFillColor(Color::Red);
	t1.setPosition(350, 400);
	

	//Objects
	Ship ship(440,900,0);
	Ship computer(440, 100,1);
	vector<Bullet> bullets,computerbullets;
	Bullet bullet(true);
	Bullet computerbullet(false);
	//QL Initialization
	QLearning QL, TEMP;
	//QL.trainingAgent(computer,ship,TEMP);
	QL.trainingAgent(computer, ship);
	//QL.greedyTacticVSQL(computer, ship);
	//QL.testAgent(computer, ship);
	//QL.greedyTacticVSBot(computer, ship);
	//QL.botvsbot(computer, ship);
	//QL.updatealfa(1);
	//QL.resetQTable();
	//QL.testAgent2(computer, ship);
	//getchar();

	//main loop
	while (w.isOpen())
	{
		
		w.clear(Color::Black);
		w.pollEvent(e);
					
		if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
		{
			w.close();
			break;
		}
		if (!pause)
		{
			//Updates
			dealaymove++;
			dealaybullets++;
			computerdealay++;
			computermovedealay++;
			computerdealaybullets++;
			text1 = tex1 + to_string(ship.getLife());
			text2 = tex2 + to_string(computer.getLife());
			text3 = tex3 + to_string(s1);
			text4 = tex4 + to_string(s2);
			playerlife.setString(text1);
			computerlife.setString(text2);
			score1.setString(text3);
			score2.setString(text4);

			for (size_t i = 0; i < bullets.size(); i++)
			{
				bullets[i].update();

				if (bullets[i].get().y <= 0 || bullets[i].get().y > gwidth)
				{
					bullets.erase(bullets.begin() + i);
				}

			}
			for (size_t i = 0; i < computerbullets.size(); i++)
			{
				computerbullets[i].update();

				if (computerbullets[i].get().y <= 0 || computerbullets[i].get().y > gwidth)
				{
					computerbullets.erase(computerbullets.begin() + i);
				}

			}
			ship.shot(bullets, bullet, dealaybullets);
			playermove=ship.update(dealaymove);
			if (computermovedealay > -1)
			{
				computermove = QL.useAgent(computer, ship, computerbullets, computerbullet, bullets, bullet, playermove, computerdealay,computerdealaybullets);
				computermovedealay = 0;
			}
			//Checking for collision
			if (!bullets.empty())
			{
				for (size_t i = 0; i < bullets.size(); i++)
				{
					if (bullets[i].checkCollision(computer.getGB()))
					{
						computer.updatelife(0);
						if (computer.getLife() == 0)
						{
							pause = 1;
						}
						bullets.erase(bullets.begin() + i);
						break;
					}
				}
			}
			if (!computerbullets.empty())
			{
				for (size_t i = 0; i < computerbullets.size(); i++)
				{
					if (computerbullets[i].checkCollision(ship.getGB()))
					{
						ship.updatelife(0);
						if (ship.getLife() == 0)
						{
							pause = 1;
						}
						computerbullets.erase(computerbullets.begin() + i);
						break;
					}
				}
			}
		}
		
		//Draw
		w.draw(sprite);
		w.draw(playerlife);
		w.draw(computerlife);
		w.draw(score1);
		w.draw(score2);

		if (pause == 1 && computer.getLife() == 0 )
		{
			w.draw(t);
			w.draw(playerlife);
			w.draw(computerlife);
			if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			{
				w.close();
				break;
			}
			s1++;
		}
		if (pause == 1 && ship.getLife() == 0)
		{
			w.draw(t1);
			w.draw(playerlife);
			w.draw(computerlife);
			if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			{
				w.close();
				break;
			}
			s2++;
		}
		w.draw(ship);
		w.draw(computer);
		for (size_t i = 0; i < bullets.size(); i++)
		{
 			w.draw(bullets[i]);
		}
		for (size_t i = 0; i < computerbullets.size(); i++)
		{
			w.draw(computerbullets[i]);
		}
		
		w.display();
	}
	return 0;
}

