#pragma once
#include "Monster.h"
#include "Const.h"
#include <stdlib.h>     /* abs */
class SmartMonster:public Monster
{
public:
	SmartMonster(sf::Vector2f position, int index, int length, int width);
	~SmartMonster();
	//overLoading for collide
	//virtual void collide(Player& player, Board& board);



	void HandlingCollisionWithSton();

	virtual void draw(sf::RenderWindow& window);
	virtual void moveMonster(sf::Time deltaTime, Player& player);
	float distanceCalculation(sf::Vector2f position, Player& player);

	void CalculateMin(int& minDistance, int tempDistance, sf::Vector2f direction);

	


protected:

};
