#pragma once
#include "Static.h"
class Gift:public Static
{
public:
	Gift(sf::Vector2f position, int index, int length, int width);
	~Gift();
	virtual void collide(Player& player, Board& board);
	void collide(Monster* monster);

protected:

};

