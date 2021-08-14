#pragma once
#include "Gift.h"
class AdditionSton:public Gift
{
public:
	AdditionSton(sf::Vector2f position, int index,int length,int width);
	~AdditionSton();
	void collide(Monster* monster);
	virtual void collide(Player& player, Board& board);

protected:

};

