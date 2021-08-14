#pragma once
#include "Static.h"
class Ston:public Static
{
public:
	Ston(sf::Vector2f position, int index, int length, int width);
	~Ston();
	virtual void collide(Player& player, Board& board);
	void collide(Monster* monster);


protected:

};
