#pragma once

//#include "Board.h"
#include "GameObject.h"
class Board;
class Dynamic:public GameObject
{
public:
	Dynamic(sf::Vector2f position, int index, int length, int width);
	~Dynamic();
	sf::Vector2f getPosition();
	sf::Vector2f getPositionDestination();
	void checkWhichDirectionWas();
	bool checkLimit(const sf::Vector2f location) const;
	 //sf::FloatRect getRectangel();
	 void updatPosition();
	//void collide(Player& player, Board& board);




	//void checkWhichDirectionWas();
	int PositionRight(int point, int size, int pointDirection);
	Dynamic()= default;
	//virtual void draw(sf::RenderWindow& window);
protected:
	sf::Vector2f m_direction;
	sf::Vector2f m_positionDestination;
	sf::Vector2f m_postDirection;
	sf::Vector2f m_startPosition;
	sf::Vector2f m_prevPosition;

};

