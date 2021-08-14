#pragma once
#include "GameObject.h"
class Board;
class Player;
class Monster;
class Static:public GameObject
{
public:
	
	Static(sf::Vector2f position, int index, int length, int width);
	~Static();
	// sf::FloatRect getRectangel();
	virtual void collide(Player& player, Board& board)=0;
	virtual void collide(Monster* monster) = 0;

	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	bool checkCollide(Player& player);
protected:

};

