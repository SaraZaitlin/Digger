#pragma once
#include "Static.h"
#include <SFML/Graphics.hpp>
class Player;
class Daimond:public Static
{
public:
	Daimond(sf::Vector2f position, int index, int length, int Width);
	~Daimond();
	void collide(Monster* monster);
	virtual void collide(Player& player, Board& board);

	//virtual void draw(sf::RenderWindow& window);

protected:
	
};

