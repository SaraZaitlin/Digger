#pragma once
#include "Gift.h"
class IncreaseTime:public Gift
{
public:
	IncreaseTime(sf::Vector2f position, int index, int length, int width);
	~IncreaseTime();
     void collide(Player& player, Board& board);
	void collide(Monster* monster);
	
protected:

};

