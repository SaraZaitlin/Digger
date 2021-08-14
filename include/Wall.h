#pragma once
#include "Static.h"
class Wall:public Static
{
public:
	Wall(sf::Vector2f position, int index, int length, int width);
	~Wall();
	virtual void collide(Player& player, Board& board);
	void collide(Monster* monster);


protected:

};

