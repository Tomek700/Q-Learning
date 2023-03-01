#pragma once
#include "Ship.h"
#include "Bullet.h"


class QLearning
{
public:
	QLearning();// Konstruktor
	~QLearning()=default;
	int randomaction(); //Wybieranie randomowej akcji
	void printQTable(); //Wypisywanie QTable
	int useAgent(Ship &computer, Ship &player, vector <Bullet>& computerbullets1, Bullet computerbullet1, vector <Bullet>& bullets, Bullet bullet, int playermove, int &dealay, int& bulletdealay); //Użycie agenta do gry komputer-człowiek
	void trainingAgent(Ship& Ship1, Ship &Ship2); // Uzupełnianie tabeli QTable
	float getReward(Ship& Ship1, Ship& Ship2, vector <Bullet>& bullets1, Bullet bullet1, vector <Bullet>& bullets2, Bullet bullet2); //Przyznawanie nagród za wykonanie akcji
	void testAgent(Ship& Ship1, Ship& Ship2);
	void testAgent2(Ship& Ship1, Ship& Ship2);
	void greedyTacticVSBot(Ship& Ship1, Ship& Ship2);
	void greedyTacticVSQL(Ship& Ship1, Ship& Ship2);
	void botvsbot(Ship& Ship1, Ship& Ship2);
	void updatealfa(float a);
	void updategamma(float a);
	void resetQTable();
	float epsilon = 1;

private:
	float********** QTab;
	double gamma = 0.7;
	double alfa = 0.9;
	
};


