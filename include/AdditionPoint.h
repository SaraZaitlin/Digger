#pragma once
#include "Gift.h"
class AdditionPoint :public Gift
{
public:
	AdditionPoint(sf::Vector2f position, int index,int length,int Width);
	~AdditionPoint();
	virtual void collide(Player& player, Board& board);
	void collide(Monster* monster);

protected:

};
