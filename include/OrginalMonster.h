#pragma once
#include "Monster.h"
#include <stdlib.h>
#include<time.h> 
#include "Player.h"
#include "Const.h"
class OrginalMonster:public Monster
{
public:



	OrginalMonster(sf::Vector2f position, int index, int length, int width);
	~OrginalMonster();
	virtual void moveMonster(sf::Time deltaTime, Player& player);
	virtual void draw(sf::RenderWindow& window);

	void HandlingCollisionWithSton();

	//overLoading for collide
	//virtual void collide(Player& player, Board& board);


protected:
	
};
