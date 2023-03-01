#include "pch.h"
#include "Computer.h"
#include "iostream"
//#include <cstdlib>
#include <ctime>
using namespace std;

QLearning::QLearning()
{
	QTab = new float********* [sectors];
	for (size_t j = 0; j < sectors; j++)
	{
		QTab[j] = new float******** [sectors];
		for (size_t k = 0; k < sectors; k++)
		{
			QTab[j][k] = new float******* [3];
			for (size_t rr1 = 0; rr1 < 3; rr1++)
			{
				QTab[j][k][rr1] = new float****** [sectors];
				for (size_t n = 0; n < sectors + 1; n++)
				{
					QTab[j][k][rr1][n] = new float***** [2];
					for (size_t o = 0; o < 2; o++)
					{
						QTab[j][k][rr1][n][o] = new float**** [2];
						for (size_t p = 0; p < 2; p++)
						{
							QTab[j][k][rr1][n][o][p] = new float*** [2];
							for (size_t r = 0; r < 2; r++)
							{
								QTab[j][k][rr1][n][o][p][r] = new float** [2];
								for (size_t s = 0; s < 2; s++)
								{
									QTab[j][k][rr1][n][o][p][r][s] = new float* [2];
									for (size_t t = 0; t < 2; t++)
									{
										QTab[j][k][rr1][n][o][p][r][s][t] = new float[actions];
									}
								}
							}
						}
					}
				}
			}	
		}
	}

	for (int i = 0; i < sectors; i++)
	{
		for (size_t j = 0; j < sectors; j++)
		{
			for (size_t rr1 = 0; rr1 < 3; rr1++)
			{
				for (size_t m = 0; m < sectors + 1; m++)
				{
					for (size_t n = 0; n < 2; n++)
					{
						for (size_t o = 0; o < 2; o++)
						{
							for (size_t p = 0; p < 2; p++)
							{
								for (size_t r = 0; r < 2; r++)
								{
									for (size_t s = 0; s < 2; s++)
									{
										for (size_t t = 0; t < actions; t++)
										{
											QTab[i][j][rr1][m][n][o][p][r][s][t] = 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


void QLearning::updatealfa(float a)
{
	alfa += 0.1;
}


void QLearning::updategamma(float a)
{
	gamma += 0.1;
	cout << "Gamma wynosi:" << gamma << endl;
}

void QLearning::resetQTable()
{
	for (int i = 0; i < sectors; i++)
	{
		for (size_t j = 0; j < sectors; j++)
		{
			for (size_t rr1 = 0; rr1 < 3; rr1++)
			{
				for (size_t m = 0; m < sectors + 1; m++)
				{
					for (size_t n = 0; n < 2; n++)
					{
						for (size_t o = 0; o < 2; o++)
						{
							for (size_t p = 0; p < 2; p++)
							{
								for (size_t r = 0; r < 2; r++)
								{
									for (size_t s = 0; s < 2; s++)
									{
										for (size_t t = 0; t < actions; t++)
										{
												QTab[i][j][rr1][m][n][o][p][r][s][t] = 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
/*
QLearning::~QLearning() {

}
*/

int QLearning::randomaction()
{
	int k = (rand() % 4) + 0;
	return (k);
}

void QLearning::printQTable()
{
	for (int i = 0; i < sectors; i++)
	{
		cout << i << ". ";
		for (size_t j = 0; j < sectors; j++)
		{
			cout << j << endl;
			for (size_t rr1 = 0; rr1 < 3; rr1++)
			{
				for (size_t m = 0; m < sectors + 1; m++)
				{
					for (size_t n = 0; n < 2; n++)
					{
						for (size_t o = 0; o < 2; o++)
						{
							for (size_t p = 0; p < 2; p++)
							{
								for (size_t r = 0; r < 2; r++)
								{
									for (size_t s = 0; s < 2; s++)
									{
										for (size_t t = 0; t < actions; t++)
										{
											cout << QTab[i][j][rr1][m][n][o][p][r][s][t] << " ";
										}
										cout << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


int QLearning::useAgent(Ship& computer, Ship& player, vector <Bullet>& computerbullets, Bullet computerbullet, vector <Bullet>& bullets, Bullet bullet, int playermove, int& dealay, int& bulletdealay)
{
	bool h;

	int current_state1 = computer.getCor().x / 80;
	int current_state2 = player.getCor().x / 80;
	float max = 0;
	int a = 0;
	int ra1 = 0;
	int b = 0;
	int bc = 0;
	int t = 0;
	int s1 = 0, s2 = 0, s3 = 0, sp = 0;
	int mb = 0;

	if (a==100)
	{
		/*
		ra1 = randomaction();
		if (current_state1 == 0)
		{
			while (ra1 == 0)
			{
				ra1 = randomaction();
			}
		}
		else if (current_state1 == sectors - 1)
		{
			while (ra1 == 1)
			{
				ra1 = randomaction();
			}
		}

		switch (ra1)
		{
		case 0:
			computer.update(0, dealay);
			break;
		case 1:
			h = computer.update(1, dealay);
			break;
		case 2:
			h = computer.update(10, dealay);
			break;
		case 3:
			computer.shot(computerbullets, computerbullet, bulletdealay, 1);
			break;
		default:
			cout << "No action!" << endl;
			break;
		}

		if (ra1 == 0 || ra1 == 3)
		{
			t = 0;
		}
		else if (ra1 == 1)
		{
			t = 1;
		}
		else {
			t = 2;
		}


		return t;
		*/
	}
	bc = 0;
	if (!bullets.empty())
	{
		bc = bullets.front().get().x / 80 ;
		
		if (abs(computer.getCor().x - bullets.front().get().x) < 40)
		{
			b = 1;
		}
		
		if (bullets.front().get().y < 900 && bullets.front().get().y > 700)
		{
			s1 = 1;
		} 
		if (bullets.front().get().y <= 700 && bullets.front().get().y > 400)
		{
			s2 = 1;
		}
		if (bullets.front().get().y <= 400 && bullets.front().get().y > 100)
		{
			s3 = 1;
		}
	
	}

	if (!computerbullets.empty())
	{
		if (abs(player.getCor().x - computerbullets.front().get().x) < 40)
		{
			mb = 1;
		}
	}


	max=QTab[current_state1][current_state2][playermove][bc][b][s1][s2][s3][mb][0];

		for (size_t z = 0; z < actions; z++)
		{
			if (QTab[current_state1][current_state2][playermove][bc][b][s1][s2][s3][mb][z] > max)
			{
				max = QTab[current_state1][current_state2][playermove][bc][b][s1][s2][s3][mb][z];
				a = z;
			}
		}

		switch (a)
		{
		case 0:
			computer.update(0, dealay);
			break;
		case 1:
			h = computer.update(1, dealay);
			break;
		case 2:
			h = computer.update(10, dealay);
			break;
		case 3:
			computer.shot(computerbullets, computerbullet, bulletdealay, 1);
			break;
		default:
			cout << "No action!" << endl;
			break;
		}


		if (a == 0 || a == 3)
		{
			a = 0;
		}
		else if (a == 1)
		{
			t = 1;
		}
		else {
			t = 2;
		}

		return t;
	
}


float QLearning::getReward(Ship& Ship1, Ship& Ship2, vector <Bullet>& bullets1, Bullet bullet1, vector <Bullet>& bullets2, Bullet bullet2)
{
	float reward = 0;
	if (!bullets1.empty())
	{
		for (size_t i = 0; i < bullets1.size(); i++)
		{
			if (bullets1[i].checkCollision(Ship2.getGB()))
			{
				Ship2.updatelife(0);
				reward += 1;
				if (Ship2.getLife() == 0)
				{
					reward += 100;
				}
				bullets1.erase(bullets1.begin() + i);
				break;
			}
		}	
	}
	if (!bullets2.empty())
	{
		for (size_t i = 0; i < bullets2.size(); i++)
		{
			if (bullets2[i].checkCollision(Ship1.getGB()))
			{
				Ship1.updatelife(0);
				reward -= 1;
				if (Ship1.getLife() == 0)
				{
					reward -= 10;
				}
				bullets2.erase(bullets2.begin() + i);
				break;
			}
		}
	}
	reward -= 0.1;

	return reward;
}

void QLearning::trainingAgent(Ship& Ship1, Ship& Ship2)
{
	vector<Bullet> bullets1, bullets2;
	Bullet bullet1(false), bullet2(true);
	int dealay1 = 0;
	int dealay2 = 0;
	int dealay3 = 0;
	int dealay4 = 0;
	float max = 0;
	float max1 = 0;
	float max2 = 0;
	bool h = 0;
	int ra1 = 0, ra2 = 0;
	int move = 0, move2 = 0;
	int temp = 0;
	double wreward = 0;
	double globalreward = 0;
	int bc=0;
	int bc1 = 0;
	int mb1 = 0;
	size_t bo1 = 0, bo2 = 0, bn1 = 0, bn2 = 0;
	size_t so1 = 0, so2 = 0, so3 = 0, sn1 = 0, sn2 = 0, sn3 = 0, sp = 0;
	size_t mb = 0;
	int w = 0;
	int w1 = 0;

	int stepsnumber = 0;
	int current_pos1, current_pos2, next_pos1 = 0, next_pos2 = 0;
	int temp1=0;

	int noi = 0;
	int lc = 10000;
	float a = lc;
	while (w+w1!=lc)//główna pętla(liczba cykli uczenia bota)
	{
		stepsnumber++;
		current_pos1 = Ship1.getCor().x / 80;
		current_pos2 = Ship2.getCor().x / 80;
		h = 0;
		bc = 0;
		bo1 = 0;
		bo2 = 0;
		bn1 = 0;
		bn2 = 0;
		so1 = 0, so2 = 0, so3 = 0, sn1 = 0, sn2 = 0, sn3 = 0, sp = 0;
		mb = 0;
		dealay1 = dealay1 + 10;
		dealay2 = dealay2 + 10;
		dealay3 = dealay3 + 50;
		dealay4 = dealay4 + 50;

		//Wybranie losowej akcji i sprawdzenie poprawności akcji
	
		ra1 = randomaction();
		ra2 = randomaction();

		if (!bullets1.empty())
		{
			if (abs(Ship2.getCor().x - bullets1.front().get().x) < 40)
			{
				mb = 1;
			}
		}

		if (!bullets2.empty())
		{
			bc = bullets2.front().get().x / 80;

			if (abs(Ship1.getCor().x - bullets2.front().get().x) < 40)
			{
				bo1 = 1;
			}
			if (bullets2.front().get().y < 900 && bullets2.front().get().y > 700)
			{
				so1 = 1;
			}
			if (bullets2.front().get().y <= 700 && bullets2.front().get().y > 400)
			{
				so2 = 1;
			}
			if (bullets2.front().get().y <= 400 && bullets2.front().get().y > 100)
			{
				so3 = 1;
			}
		}

		
		if (ra2 == 0 || ra2 == 3)
		{
			move = 0;
		}
		else if (ra2 == 1)
		{
			move = 1;
		}
		else {
			move = 2;
		}


		max = QTab[current_pos1][current_pos2][move][bc][bo1][so1][so2][so3][mb][0];
		if ((float)rand() / RAND_MAX >= epsilon)
		{
			temp1++;
			for (size_t z = 0; z < actions; z++)
			{
				if (QTab[current_pos1][current_pos2][move][bc][bo1][so1][so2][so3][mb][z] > max)
				{
					max = QTab[current_pos1][current_pos2][move][bc][bo1][so1][so2][so3][mb][z];
					ra1 = z;
				}
			}
		}

		switch (ra1)
		{
		case 0:
			Ship1.update(0, temp);
			next_pos1 = current_pos1;
			break;
		case 1:
			h = Ship1.update(1, dealay3);
			if (h)
			{
				next_pos1 = current_pos1 - 1;
			}
			break;
		case 2:
			h = Ship1.update(10, dealay3);
			if (h)
			{
				next_pos1 = current_pos1 + 1;
			}
			break;
		case 3:
			Ship1.shot(bullets1, bullet1, dealay1, 1);
			next_pos1 = current_pos1;

			break;
		default:
			cout << "No action!" << endl;
			break;
		}
		h = 0;

		//Aktualizowanie pocisków
		for (size_t i = 0; i < bullets1.size(); i++)
		{
			bullets1[i].update();

			if (bullets1[i].get().y <= 0 || bullets1[i].get().y > gwidth)
			{
				bullets1.erase(bullets1.begin() + i);
			}

		}
	
		switch (ra2)
		{
		case 0:
			Ship2.update(0, temp);
			next_pos2 = current_pos2;
			break;
		case 1:
			h = Ship2.update(1, dealay4);
			if (h)
			{
				next_pos2 = current_pos2 - 1;
			}
			break;
		case 2:
			h = Ship2.update(10, dealay4);
			if (h)
			{
				next_pos2 = current_pos2 + 1;
			}
			break;
		case 3:
			Ship2.shot(bullets2, bullet2, dealay2, 1);
			next_pos2 = current_pos2;
			break;
		default:
			cout << "No action!" << endl;
			break;
		}
	
		for (size_t i = 0; i < bullets2.size(); i++)
		{
			bullets2[i].update();

			if (bullets2[i].get().y <= 0 || bullets2[i].get().y > gwidth)
			{
				bullets2.erase(bullets2.begin() + i);
			}

		}

		//Przyznanie nagrody
		float reward1 = getReward(Ship1, Ship2, bullets1, bullet1, bullets2, bullet2);
		wreward = wreward + reward1;
		globalreward = globalreward + reward1;
	
		//Czy kula leci w kierunku statku
		if (!bullets2.empty())
		{	
			bc1 = bullets2.front().get().x / 80;

			if (abs(Ship1.getCor().x - bullets2.front().get().x) < 40)
			{
				bn1 = 1;
			}
		
			if (bullets2.front().get().y < 900 && bullets2.front().get().y > 700)
			{
				sn1 = 1;
			}
			if (bullets2.front().get().y <= 700 && bullets2.front().get().y > 400)
			{
				sn2 = 1;
			}
			if (bullets2.front().get().y <= 400 && bullets2.front().get().y > 100)
			{
				sn3 = 1;
			}
		}

		mb1 = 0;
		if (!bullets1.empty())
		{
			if (abs(Ship2.getCor().x - bullets1.front().get().x) < 40)
			{
				mb1 = 1;
			}
		}

		//Wybieranie przyszłych najlepszych akcji
		max1 = QTab[next_pos1][next_pos2][move][bc1][bn1][sn1][sn2][sn3][mb1][0];
		
			for (size_t z = 0; z < actions; z++)
			{
				if (QTab[next_pos1][next_pos2][move][bc1][bn1][sn1][sn2][sn3][mb1][z] > max1)
				{
					max1 = QTab[next_pos1][next_pos2][move][bc1][bn1][sn1][sn2][sn3][mb1][z];
				}
			}

		//Uaktualnienie QTable		
		QTab[current_pos1][current_pos2][move][bc][bo1][so1][so2][so3][mb][ra1] = QTab[current_pos1][current_pos2][move][bc][bo1][so1][so2][so3][mb][ra1] + alfa * (reward1 + gamma * max1 - QTab[current_pos1][current_pos2][move][bc][bo1][so1][so2][so3][mb][ra1]);
	
		//Sprawdzanie warunków końca gry i w razie potrzeby rersetowanie świata gry
		if (Ship1.getLife() == 0 || Ship2.getLife() == 0)
		{
			if (Ship2.getLife() == 0)
			{
				w++;
			}

			if (Ship1.getLife() == 0)
			{
				w1++;
			}

			//cout << wreward << "," <<endl;
			wreward = 0;
			Ship1.resetLife();
			Ship2.resetLife();
			Ship1.setCor(440, 100);
			Ship2.setCor(440, 900);
			epsilon = epsilon - 1/a;
			//cout << epsilon << endl;

			for (size_t i = 0; i < bullets1.size(); i++)
			{
				bullets1.erase(bullets1.begin() + i);
			}
			for (size_t i = 0; i < bullets2.size(); i++)
			{
				bullets2.erase(bullets2.begin() + i);
			}
		}
		//Nadanie stanów aktaulnych statkom i resetowanie zmiennych pomocniczych
		current_pos1 = next_pos1;
		current_pos2 = next_pos2;
	}
	
	Ship1.resetLife();
	Ship2.resetLife();
	Ship1.setCor(440, 100);
	Ship2.setCor(440, 900);
	cout << temp1 << endl;
	cout << "Srednia nagroda wyniosla:" << globalreward / (lc) << endl;
	cout << "Done" << endl;
	cout << "Liczba krokow wyniosla" << stepsnumber / lc;
	//printQTable();
	//getchar();
}


void QLearning::testAgent(Ship& Ship1, Ship& Ship2)
{

	vector<Bullet> bullets1, bullets2;
	Bullet bullet1(false), bullet2(true);

	int noi=0;
	int dealay1 = 0;
	int dealay2 = 0;
	int dealay3 = 0;
	int dealay4 = 0;
	int computermove=0;
	int playermove = 0;
	float max1 = 0;
	float max2 = 0;
	bool h = 0;
	int ra1 = 0, ra2 = 0;
	int t1 = 0, t2 = 0;
	int temp = 0;
	size_t bo1 = 0, bo2 = 0, bn1 = 0, bn2 = 0;
	size_t so1 = 0, so2 = 0, so3 = 0, sn1 = 0, sn2 = 0, sn3 = 0, sp = 0;
	float reward = 0, wreward = 0;

	int w = 0;
	int w1 = 0;

	while (w+w1!=100)
	{
		noi++;
		dealay1 = dealay1 + 10;
		dealay2 = dealay2 + 10;
		dealay3 = dealay3 + 50;
		dealay4 = dealay4 + 50;

		ra1 = randomaction();

		switch (ra1)
		{
		case 0:
			Ship2.update(0, temp);
			break;
		case 1:
			h = Ship2.update(1, dealay3);
			break;
		case 2:
			h = Ship2.update(10, dealay3);
			break;
		case 3:
			Ship2.shot(bullets2, bullet2, dealay1, 1);
			break;
		default:
			cout << "No action!" << endl;
			break;
		}
		h = 0;
		if (ra1 == 0 || ra1 == 3)
		{
			playermove = 0;
		}
		else if (ra1 == 1)
		{
			playermove = 1;
		}
		else {
			playermove = 2;
		}

		useAgent(Ship1, Ship2, bullets1, bullet1, bullets2, bullet2, playermove, dealay4, dealay2);

		//Aktualizowanie pocisków
		for (size_t i = 0; i < bullets1.size(); i++)
		{
			bullets1[i].update();

			if (bullets1[i].get().y <= 0 || bullets1[i].get().y > gwidth)
			{
				bullets1.erase(bullets1.begin() + i);
			}

		}
		for (size_t i = 0; i < bullets2.size(); i++)
		{
			bullets2[i].update();

			if (bullets2[i].get().y <= 0 || bullets2[i].get().y > gwidth)
			{
				bullets2.erase(bullets2.begin() + i);
			}

		}


		reward = getReward(Ship1, Ship2, bullets1, bullet1, bullets2, bullet2);
		wreward = wreward + reward;

		
		if (Ship1.getLife() == 0 || Ship2.getLife() == 0)
		{
			if (Ship2.getLife() == 0)
			{
				w++;
			}

			if (Ship1.getLife() == 0)
			{
				w1++;
			}

			Ship1.resetLife();
			Ship2.resetLife();
			Ship1.setCor(440, 100);
			Ship2.setCor(440, 900);

			for (size_t i = 0; i < bullets1.size(); i++)
			{
				bullets1.erase(bullets1.begin() + i);
			}
			for (size_t i = 0; i < bullets2.size(); i++)
			{
				bullets2.erase(bullets2.begin() + i);
			}
		}
		//cout << noi << endl;

	}
	cout << "Bot z Q-Learningiem wygral:" << w << endl;
	cout << "Bot losowy wygral:" << w1 << endl;
	cout << "Liczba iteracji wyniosla" << noi << endl;
	cout << "Srednia nagroda wyniosla" << wreward / (w + w1);
}


void QLearning::testAgent2(Ship& Ship1, Ship& Ship2)
{

	vector<Bullet> bullets1, bullets2;
	Bullet bullet1(false), bullet2(true);

	int noi = 0;
	int dealay1 = 0;
	int dealay2 = 0;
	int dealay3 = 0;
	int dealay4 = 0;
	int computermove = 0;
	int playermove = 0;
	float max1 = 0;
	float max2 = 0;
	bool h = 0;
	int ra1 = 0, ra2 = 0;
	int t1 = 0, t2 = 0;
	int temp = 0;
	size_t bo1 = 0, bo2 = 0, bn1 = 0, bn2 = 0;
	size_t so1 = 0, so2 = 0, so3 = 0, sn1 = 0, sn2 = 0, sn3 = 0, sp = 0;

	int w = 0;
	int w1 = 0;

	while (w + w1 != 100)
	{
		noi++;
		dealay1 = dealay1 + 10;
		dealay2 = dealay2 + 10;
		dealay3 = dealay3 + 50;
		dealay4 = dealay4 + 50;


		useAgent(Ship2, Ship1, bullets2, bullet2, bullets1, bullet1, computermove ,dealay3, dealay4);
		useAgent(Ship1, Ship2, bullets1, bullet1, bullets2, bullet2, playermove, dealay1, dealay2);
		//Aktualizowanie pocisków
		for (size_t i = 0; i < bullets1.size(); i++)
		{
			bullets1[i].update();

			if (bullets1[i].get().y <= 0 || bullets1[i].get().y > gwidth)
			{
				bullets1.erase(bullets1.begin() + i);
			}

		}
		for (size_t i = 0; i < bullets2.size(); i++)
		{
			bullets2[i].update();

			if (bullets2[i].get().y <= 0 || bullets2[i].get().y > gwidth)
			{
				bullets2.erase(bullets2.begin() + i);
			}

		}

		if (!bullets1.empty())
		{
			for (size_t i = 0; i < bullets1.size(); i++)
			{
				if (bullets1[i].checkCollision(Ship2.getGB()))
				{
					Ship2.updatelife(0);
					bullets1.erase(bullets1.begin() + i);
					break;
				}
			}
		}
		if (!bullets2.empty())
		{
			for (size_t i = 0; i < bullets2.size(); i++)
			{
				if (bullets2[i].checkCollision(Ship1.getGB()))
				{
					Ship1.updatelife(0);
					bullets2.erase(bullets2.begin() + i);
					break;
				}
			}
		}

		if (Ship1.getLife() == 0 || Ship2.getLife() == 0)
		{
			if (Ship2.getLife() == 0)
			{
				w++;
			}

			if (Ship1.getLife() == 0)
			{
				w1++;
			}

			Ship1.resetLife();
			Ship2.resetLife();
			Ship1.setCor(440, 100);
			Ship2.setCor(440, 900);

			for (size_t i = 0; i < bullets1.size(); i++)
			{
				bullets1.erase(bullets1.begin() + i);
			}
			for (size_t i = 0; i < bullets2.size(); i++)
			{
				bullets2.erase(bullets2.begin() + i);
			}
		}

		
		//cout << noi << endl;

	}
	cout << "Bot z Q-Learningiem 1 wygral:" << w << endl;
	cout << "Bot z Q-Learningiem 2 wygral:" << w1 << endl;
	cout << "Srednia iczba iteracji wyniosla" << noi/(w+w1) << endl;
}

void QLearning::greedyTacticVSBot(Ship& Ship1, Ship& Ship2)
{

	vector<Bullet> bullets1, bullets2;
	Bullet bullet1(false), bullet2(true);

	int noi = 0;
	int dealay1 = 0;
	int dealay2 = 0;
	int dealay3 = 0;
	int dealay4 = 0;
	int computermove = 0;
	int playermove = 0;
	float max1 = 0;
	float max2 = 0;
	bool h = 0;
	int ra1 = 0, ra2 = 0;
	int t1 = 0, t2 = 0;
	int temp = 0;
	size_t bo1 = 0, bo2 = 0, bn1 = 0, bn2 = 0;
	size_t so1 = 0, so2 = 0, so3 = 0, sn1 = 0, sn2 = 0, sn3 = 0, sp = 0;
	float reward=0;
	float wreward = 0;

	int w = 0;
	int w1 = 0;
	int a;

	while (w + w1 != 100)
	{
		noi++;
		dealay1 = dealay1 + 10;
		dealay2 = dealay2 + 10;
		dealay3 = dealay3 + 50;
		dealay4 = dealay4 + 50;
		//Bot losowy
		ra1 = randomaction();
	

		switch (ra1)
		{
		case 0:
			Ship2.update(0, temp);
			break;
		case 1:
			h = Ship2.update(1, dealay3);
			break;
		case 2:
			h = Ship2.update(10, dealay3);
			break;
		case 3:
			Ship2.shot(bullets2, bullet2, dealay1, 1);
			break;
		default:
			cout << "No action!" << endl;
			break;
		}
		h = 0;


		//GreedyTactic
		if (bullets2.empty())
		{
			if (Ship1.getCor().x == Ship2.getCor().x)
			{
				Ship1.shot(bullets1, bullet1, dealay2, 1);
			}
			else if (!(Ship1.getCor().x == Ship2.getCor().x) && Ship1.getCor().x - Ship2.getCor().x > 0)
			{
				Ship1.update(1, dealay4);
			}
			else if (!(Ship1.getCor().x == Ship2.getCor().x) && Ship1.getCor().x - Ship2.getCor().x < 0)
			{
				Ship1.update(10, dealay4);
			}
		}
		else if (!bullets2.empty())
		{

			if (Ship1.getCor().x == Ship2.getCor().x && !(bullets2.front().get().y <= 400 && bullets2.front().get().y > 0))
			{
				Ship1.shot(bullets1, bullet1, dealay2, 2);
			}
			else if (Ship1.getCor().x == Ship2.getCor().x && bullets2.front().get().y <= 400 && bullets2.front().get().y > 0 && bullets2.front().get().y > 0 && Ship1.getCor().x - 40 == 0)
			{
				Ship1.update(10, dealay4);
			}
			else if (Ship1.getCor().x == Ship2.getCor().x && bullets2.front().get().y <= 400 && bullets2.front().get().y > 0 && bullets2.front().get().y > 0 && Ship1.getCor().x + 40 == glength)
			{
				Ship1.update(1, dealay4);
			}
			else if (Ship1.getCor().x == Ship2.getCor().x && bullets2.front().get().y <= 400 && bullets2.front().get().y > 0 && !(bullets2.front().get().y > 0 && Ship1.getCor().x - 40 == 0) && !(bullets2.front().get().y > 0 && Ship1.getCor().x + 40 == glength))
			{
				a = rand() % 3 + 1;
				if (a == 1)
				{
					Ship1.update(1, dealay4);
				}
				if (a == 2)
				{
					Ship1.update(10, dealay4);
				}
			}
			else if (!(Ship1.getCor().x == Ship2.getCor().x) && bullets2.front().get().y <= 400 && bullets2.front().get().y > 0 && bullets2.front().get().y > 0 && Ship1.getCor().x - 40 == 0 )
			{
				Ship1.update(10, dealay4);
			}
			else if (!(Ship1.getCor().x == Ship2.getCor().x) && bullets2.front().get().y <= 400 && bullets2.front().get().y > 0 && bullets2.front().get().y > 0 && Ship1.getCor().x + 40 == glength)
			{
				Ship1.update(1, dealay4);
			}
			else if (!(Ship1.getCor().x == Ship2.getCor().x) && bullets2.front().get().y <= 400 && bullets2.front().get().y > 0 && !(bullets2.front().get().y > 0 && Ship1.getCor().x - 40 == 0) && !(bullets2.front().get().y > 0 && Ship1.getCor().x + 40 == glength))
			{
				a = rand() % 3 + 1;
				if (a == 1)
				{
					Ship1.update(1, dealay4);
				}
				if (a == 2)
				{
					Ship1.update(10, dealay4);
				}
			}
			else if (!(Ship1.getCor().x == Ship2.getCor().x) && !(bullets2.front().get().y <= 400 && bullets2.front().get().y > 0 ) && Ship1.getCor().x - Ship2.getCor().x > 0)
			{
				Ship1.update(1, dealay4);
			}
			else if (!(Ship1.getCor().x == Ship2.getCor().x) && !(bullets2.front().get().y <= 400 && bullets2.front().get().y > 0) && Ship1.getCor().x - Ship2.getCor().x < 0)
			{
				Ship1.update(10, dealay4);
			}
			
		}
		
		reward = getReward(Ship1, Ship2, bullets1, bullet1, bullets2, bullet2);
		wreward = wreward + reward;
	
		//Aktualizowanie pocisków
		for (size_t i = 0; i < bullets1.size(); i++)
		{
			bullets1[i].update();

			if (bullets1[i].get().y <= 0 || bullets1[i].get().y > gwidth)
			{
				bullets1.erase(bullets1.begin() + i);
			}

		}
		for (size_t i = 0; i < bullets2.size(); i++)
		{
			bullets2[i].update();

			if (bullets2[i].get().y <= 0 || bullets2[i].get().y > gwidth)
			{
				bullets2.erase(bullets2.begin() + i);
			}

		}


		if (Ship1.getLife() == 0 || Ship2.getLife() == 0)
		{
			if (Ship2.getLife() == 0)
			{
				w++;
			}

			if (Ship1.getLife() == 0)
			{
				w1++;
			}
			cout << wreward << "," << endl;
			wreward = 0;
			Ship1.resetLife();
			Ship2.resetLife();
			Ship1.setCor(440, 100);
			Ship2.setCor(440, 900);

			for (size_t i = 0; i < bullets1.size(); i++)
			{
				bullets1.erase(bullets1.begin() + i);
			}
			for (size_t i = 0; i < bullets2.size(); i++)
			{
				bullets2.erase(bullets2.begin() + i);
			}
		}
		//cout << noi << endl;

	}
	cout << "Bot z taktyka zachlanna wygral:" << w << endl;
	cout << "Bot lsoswy wygral:" << w1<< endl;
	cout << "Liczba iteracji wyniosla:" << noi << endl;
	cout << "Srednia nagroda taktyki zachlannej wyniosla:" << wreward / (w + w1) << endl;
}

void QLearning::greedyTacticVSQL(Ship& Ship1, Ship& Ship2)
{
	vector<Bullet> bullets1, bullets2;
	Bullet bullet1(false), bullet2(true);

	int noi = 0;
	int dealay1 = 0;
	int dealay2 = 0;
	int dealay3 = 0;
	int dealay4 = 0;
	int computermove = 0;
	int playermove = 0;
	float max1 = 0;
	float max2 = 0;
	bool h = 0;
	int ra1 = 0, ra2 = 0;
	int t1 = 0, t2 = 0;
	int temp = 0;
	size_t bo1 = 0, bo2 = 0, bn1 = 0, bn2 = 0;
	size_t so1 = 0, so2 = 0, so3 = 0, sn1 = 0, sn2 = 0, sn3 = 0, sp = 0;
	float reward = 0;
	float wreward = 0;

	int w = 0;
	int w1 = 0;
	int a;

	while (w + w1 != 100)
	{
		noi++;
		dealay1 = dealay1 + 10;
		dealay2 = dealay2 + 10;
		dealay3 = dealay3 + 50;
		dealay4 = dealay4 + 50;
		//Bot losowy

		useAgent(Ship1, Ship2, bullets1, bullet1, bullets2, bullet2, playermove, dealay1, dealay3);


		//Algorytm zachlanny
		if (bullets1.empty())
		{
			if (Ship2.getCor().x == Ship1.getCor().x)
			{
				Ship2.shot(bullets2, bullet2, dealay2, 1);
			}
			else if (!(Ship2.getCor().x == Ship1.getCor().x) && Ship2.getCor().x - Ship1.getCor().x > 0)
			{
				Ship2.update(1, dealay4);
			}
			else if (!(Ship2.getCor().x == Ship1.getCor().x) && Ship2.getCor().x - Ship1.getCor().x < 0)
			{
				Ship2.update(10, dealay4);
			}
		}
		else if (!bullets1.empty())
		{

			if (Ship2.getCor().x == Ship1.getCor().x && !(bullets1.front().get().y <= 400 && bullets1.front().get().y > 0))
			{
				Ship2.shot(bullets2, bullet2, dealay2, 2);
			}
			else if (Ship2.getCor().x == Ship1.getCor().x && bullets1.front().get().y <= 400 && bullets1.front().get().y > 0 && bullets1.front().get().y > 0 && Ship2.getCor().x - 40 == 0)
			{
				Ship2.update(10, dealay4);
			}
			else if (Ship2.getCor().x == Ship1.getCor().x && bullets1.front().get().y <= 400 && bullets1.front().get().y > 0 && bullets1.front().get().y > 0 && Ship2.getCor().x + 40 == glength)
			{
				Ship2.update(1, dealay4);
			}
			else if (Ship2.getCor().x == Ship1.getCor().x && bullets1.front().get().y <= 400 && bullets1.front().get().y > 0 && !(bullets1.front().get().y > 0 && Ship2.getCor().x - 40 == 0) && !(bullets1.front().get().y > 0 && Ship2.getCor().x + 40 == glength))
			{
				a = rand() % 3 + 1;
				if (a == 1)
				{
					Ship2.update(1, dealay4);
				}
				if (a == 2)
				{
					Ship2.update(10, dealay4);
				}
			}
			else if (!(Ship2.getCor().x == Ship1.getCor().x) && bullets1.front().get().y <= 400 && bullets1.front().get().y > 0 && bullets1.front().get().y > 0 && Ship2.getCor().x - 40 == 0)
			{
				Ship2.update(10, dealay4);
			}
			else if (!(Ship2.getCor().x == Ship1.getCor().x) && bullets1.front().get().y <= 400 && bullets1.front().get().y > 0 && bullets1.front().get().y > 0 && Ship2.getCor().x + 40 == glength)
			{
				Ship2.update(1, dealay4);
			}
			else if (!(Ship2.getCor().x == Ship1.getCor().x) && bullets1.front().get().y <= 400 && bullets1.front().get().y > 0 && !(bullets1.front().get().y > 0 && Ship2.getCor().x - 40 == 0) && !(bullets1.front().get().y > 0 && Ship2.getCor().x + 40 == glength))
			{
				a = rand() % 3 + 1;
				if (a == 1)
				{
					Ship2.update(1, dealay4);
				}
				if (a == 2)
				{
					Ship2.update(10, dealay4);
				}
			}
			else if (!(Ship2.getCor().x == Ship1.getCor().x) && !(bullets1.front().get().y <= 400 && bullets1.front().get().y > 0) && Ship2.getCor().x - Ship1.getCor().x > 0)
			{
				Ship2.update(1, dealay4);
			}
			else if (!(Ship2.getCor().x == Ship1.getCor().x) && !(bullets1.front().get().y <= 400 && bullets1.front().get().y > 0) && Ship2.getCor().x - Ship1.getCor().x < 0)
			{
				Ship2.update(10, dealay4);
			}

		}

		reward = getReward(Ship1, Ship2, bullets1, bullet1, bullets2, bullet2);
		wreward = wreward + reward;

		//Aktualizowanie pocisków
		for (size_t i = 0; i < bullets1.size(); i++)
		{
			bullets1[i].update();

			if (bullets1[i].get().y <= 0 || bullets1[i].get().y > gwidth)
			{
				bullets1.erase(bullets1.begin() + i);
			}

		}
		for (size_t i = 0; i < bullets2.size(); i++)
		{
			bullets2[i].update();

			if (bullets2[i].get().y <= 0 || bullets2[i].get().y > gwidth)
			{
				bullets2.erase(bullets2.begin() + i);
			}

		}


		if (Ship1.getLife() == 0 || Ship2.getLife() == 0)
		{
			if (Ship2.getLife() == 0)
			{
				w++;
			}

			if (Ship1.getLife() == 0)
			{
				w1++;
			}
			cout << wreward << "," << endl;
			wreward = 0;
			Ship1.resetLife();
			Ship2.resetLife();
			Ship1.setCor(440, 100);
			Ship2.setCor(440, 900);

			for (size_t i = 0; i < bullets1.size(); i++)
			{
				bullets1.erase(bullets1.begin() + i);
			}
			for (size_t i = 0; i < bullets2.size(); i++)
			{
				bullets2.erase(bullets2.begin() + i);
			}
		}
		//cout << noi << endl;

	}
	cout << "Bot QL wygral:" << w << endl;
	cout << "Bot z taktyka zachlanna:" << w1 << endl;
	cout << "Liczba iteracji wyniosla:" << noi << endl;
	cout << "Srednia nagroda bota QL wyniosla:" << wreward / (w + w1) << endl;

}


void QLearning::botvsbot(Ship& Ship1, Ship& Ship2)
{

	vector<Bullet> bullets1, bullets2;
	Bullet bullet1(false), bullet2(true);
	int noi = 0;
	int dealay1 = 0;
	int dealay2 = 0;
	int dealay3 = 0;
	int dealay4 = 0;
	int computermove = 0;
	int playermove = 0;
	float max1 = 0;
	float max2 = 0;
	bool h = 0;
	int ra1 = 0, ra2 = 0;
	int t1 = 0, t2 = 0;
	int temp = 0;
	size_t bo1 = 0, bo2 = 0, bn1 = 0, bn2 = 0;
	size_t so1 = 0, so2 = 0, so3 = 0, sn1 = 0, sn2 = 0, sn3 = 0, sp = 0;
	float reward = 0, wreward = 0;

	int w = 0;
	int w1 = 0;

	while (w + w1 != 1000)
	{
		noi++;
		dealay1 = dealay1 + 10;
		dealay2 = dealay2 + 10;
		dealay3 = dealay3 + 50;
		dealay4 = dealay4 + 50;

		ra1 = randomaction();
		ra2 = randomaction();

		switch (ra1)
		{
		case 0:
			Ship1.update(0, temp);
			break;
		case 1:
			h = Ship1.update(1, dealay3);
			break;
		case 2:
			h = Ship1.update(10, dealay3);
			break;
		case 3:
			Ship1.shot(bullets1, bullet1, dealay1, 1);
			break;
		default:
			cout << "No action!" << endl;
			break;
		}
		
		switch (ra2)
		{
		case 0:
			Ship2.update(0, temp);
			break;
		case 1:
			h = Ship2.update(1, dealay4);
			break;
		case 2:
			h = Ship2.update(10, dealay4);
			break;
		case 3:
			Ship2.shot(bullets2, bullet2, dealay2, 1);
			break;
		default:
			cout << "No action!" << endl;
			break;
		}

		//Aktualizowanie pocisków
		for (size_t i = 0; i < bullets1.size(); i++)
		{
			bullets1[i].update();

			if (bullets1[i].get().y <= 0 || bullets1[i].get().y > gwidth)
			{
				bullets1.erase(bullets1.begin() + i);
			}

		}
		for (size_t i = 0; i < bullets2.size(); i++)
		{
			bullets2[i].update();

			if (bullets2[i].get().y <= 0 || bullets2[i].get().y > gwidth)
			{
				bullets2.erase(bullets2.begin() + i);
			}

		}

		reward = getReward(Ship1, Ship2, bullets1, bullet1, bullets2, bullet2);
		wreward = wreward + reward;

		if (Ship1.getLife() == 0 || Ship2.getLife() == 0)
		{
			if (Ship2.getLife() == 0)
			{
				w++;
			}

			if (Ship1.getLife() == 0)
			{
				w1++;
			}

			//cout << wreward <<","<< endl;
			//wreward = 0;
			Ship1.resetLife();
			Ship2.resetLife();
			Ship1.setCor(440, 100);
			Ship2.setCor(440, 900);

			for (size_t i = 0; i < bullets1.size(); i++)
			{
				bullets1.erase(bullets1.begin() + i);
			}
			for (size_t i = 0; i < bullets2.size(); i++)
			{
				bullets2.erase(bullets2.begin() + i);
			}
		}
		//cout << noi << endl;

	}
	cout << "Bot losowy 1 wygral:" << w << endl;
	cout << "Bot losowy 2 wygral:" << w1 << endl;
	cout << "Srednia liczba iteracji wyniosla" << noi/ (w + w1) << endl;
	cout << "Srednia nagroda wyniosla" << wreward / (w + w1);
}
