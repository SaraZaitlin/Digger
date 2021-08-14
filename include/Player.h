#pragma once
#include "resourc.h"
#include "Dynamic.h"
#include <math.h>       /* floor */
#include <stdlib.h>     /* abs */
//#include "Monster.h"
class Board;
class Monster;
class Player:public Dynamic
{
public:
	Player(sf::Vector2f position, int index, int length, int width);
	~Player();
	void updateInformationDisplay(int ston, int time);
	Player()= default;
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	bool HandlingCollision();
	void DeleteObject(Board& board);
	void updatLife();
	bool updatSton(int num);
	void updatSumDaimond();
	void  updatIncreaseTime();
	void updatPoint(int num);


	void setPosition(sf::Vector2f position);
	void setSize(int length, int width);
	void Bootfeatures();
	void setDirection(sf::Keyboard::Key key);
	void move(sf::Time deltaTime);
	int getMaxSton();
	bool checkTime();
	int getTime(sf::Time deltaTime);
	int getLife();
	int getPoint();
	int getDaimond();
	

protected:
	int m_maxSton;
	float m_time;
	int m_sumDaimond;
	int m_life;
	int m_point=0;
	bool m_isStartLevel=false;
};
