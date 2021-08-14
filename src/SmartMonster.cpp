#include "SmartMonster.h"
#include <iostream>
SmartMonster::SmartMonster(sf::Vector2f position, int index, int length, int width):Monster(position, index, length, width)
{
}

SmartMonster::~SmartMonster()
{
}
//פונקציה טיפול בהתנגשות באבן

void SmartMonster::HandlingCollisionWithSton()
{

}
//מציירת את האובייקט של המפלצת החכמה
void SmartMonster::draw(sf::RenderWindow& window)
{
	Monster::draw(window);
}
//פונקציית תזוזה של המפלצת החכמה
void SmartMonster::moveMonster(sf::Time deltaTime, Player& player)
{
	Monster::moveMonster(deltaTime, player);
	int tempDistance, minDistance=1000*800;
	sf::Vector2f position, direction;
	for (int i = 0; i < 4; i++)
	{
		direction =checkDirection(Direction(i));

		position = m_sprite.getPosition() + (direction * deltaTime.asSeconds());


		tempDistance = distanceCalculation(position, player);

		if (minDistance > tempDistance)
		{	
			
			//m_direction = direction;
				checkWhichDirectionWas();
			
				m_postDirection = direction;
			minDistance = tempDistance;
		}
	}


	if (std::abs(m_sprite.getPosition().x - m_positionDestination.x) <= 2 &&
		std::abs(m_sprite.getPosition().y - m_positionDestination.y) <= 2)
	{
		m_direction = m_postDirection;

	}
	

	m_sprite.move(m_direction * deltaTime.asSeconds());
	
}

//פונקציה לחישוב מרחק בין מפלצת לשחקן ע"פ חישוב מנטל
float SmartMonster::distanceCalculation(sf::Vector2f position,Player& player)
{
	//std::cout << player.getPosition().x << " " << player.getPosition().y<<std::endl;
	return((std::abs(position.x-(player.getPosition()).x))+(std::abs(position.y-(player.getPosition()).y)));
}
//מוצאת את המרחק הקטן בשביל התזוזה של המפלצת
void SmartMonster::CalculateMin(int& minDistance,int tempDistance, sf::Vector2f direction)
{
	if (minDistance > tempDistance)
	{
		minDistance = tempDistance;
		m_direction = direction;
		//std::cout << m_direction.x << "x:" << m_direction.y << "y:" << std::endl;
	}
}


	