#pragma once
#include "Dynamic.h"
#include "Player.h"
#include "Const.h"
class Monster:public Dynamic
{
public:
	Monster(sf::Vector2f position, int index, int length, int width);
	~Monster();
	virtual void moveMonster(sf::Time deltaTime,Player& player);
  void HandlingCollisionWithSton();
	void HandlingCollision();
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f checkDirection(int postDirection);

protected:
};
