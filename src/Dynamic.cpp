#include "Dynamic.h"
#include "Board.h"


Dynamic::Dynamic(sf::Vector2f position, int index, int length, int width) :
	GameObject(position, index, length, width),m_direction({0,0}), m_positionDestination(position), m_startPosition(position)
{
}

Dynamic::~Dynamic()
{
}
sf::Vector2f Dynamic::getPosition()
{
	return m_sprite.getPosition();
}
//פונקציה המחשבת את המיקום הבא
sf::Vector2f Dynamic::getPositionDestination()
{
	//std::cout << m_sprite.getPosition().x << " " << m_sprite.getPosition().y<<std::endl;
	if (m_direction.x != 0)
		return (sf::Vector2f(PositionRight(floor(m_sprite.getPosition().x), m_sprite.getGlobalBounds().width, m_direction.x), (m_sprite.getPosition().y)));

	return (sf::Vector2f((m_sprite.getPosition().x),
		(PositionRight(floor(m_sprite.getPosition().y), m_sprite.getGlobalBounds().height, m_direction.y))));

}
//פונקציה שבודקת איזה כיוון היה השחקן או המפלצת
void Dynamic::checkWhichDirectionWas()
{
	if (m_direction.x != 0)
	{
		m_positionDestination.x = PositionRight(floor(m_sprite.getPosition().x), m_sprite.getGlobalBounds().width, m_direction.x);
		m_positionDestination.y = m_sprite.getPosition().y;

	}
	else if (m_direction.y != 0)
	{
		m_positionDestination.y = PositionRight(floor(m_sprite.getPosition().y), m_sprite.getGlobalBounds().height, m_direction.y);
		m_positionDestination.x = m_sprite.getPosition().x;

	}
}
// בודקת שהאובייקט לא חורגים מגבולות המטריצה
bool Dynamic::checkLimit(const sf::Vector2f location) const
{
	return location.y < Length &&location.y>0&&
		location.x < Width && location.x > 0;
}


//פונקציה המעדכנת את המיקום של הדינאמים למיקום הקודם כאשר אינם יכולים להיכנס לתא 
void Dynamic::updatPosition()
{
	if (m_direction.x > 0)
	{
		m_sprite.setPosition(sf::Vector2f(ceil(m_prevPosition.x),
			ceil(m_prevPosition.y)));
		m_positionDestination.x = m_sprite.getPosition().x;
	}
	if (m_direction.x < 0)
	{
		m_sprite.setPosition(sf::Vector2f(floor(m_prevPosition.x + 1),
			floor(m_prevPosition.y)));
		m_positionDestination.x = m_sprite.getPosition().x;

	}
	if (m_direction.y > 0)
	{
		m_sprite.setPosition(sf::Vector2f(ceil(m_prevPosition.x),
			ceil(m_prevPosition.y - 1)));
		m_positionDestination.y = m_sprite.getPosition().y;
	}
	if (m_direction.y < 0)
	{
		m_sprite.setPosition(sf::Vector2f(floor(m_prevPosition.x),
			floor(m_prevPosition.y + 1)));
		m_positionDestination.y = m_sprite.getPosition().y;
	}

	//m_sprite.setPosition(sf::Vector2f(ceil(m_prevPosition.x),
		//ceil(m_prevPosition.y)));
}
//מחשבת את המיקום שהשחקן או המפלצת תהייה 
int Dynamic::PositionRight(int point, int size, int pointDirection)
{
	
	point = (point - (point % size));
	if (pointDirection > 0)
	{

		return point + size+1;
	}
	return point;
}
