#pragma once
#include <SFML/Graphics.hpp>
#include "resourc.h"
//#include "Player.h"
//#include "Board.h"
class GameObject
{
public:
	GameObject(sf::Vector2f position,int index, int length, int width);
	~GameObject();
	sf::FloatRect getRectangel();
	GameObject ()= default;


	virtual void draw(sf::RenderWindow& window) = 0;

protected:
	sf::Sprite m_sprite;
};

