
#include "OrginalMonster.h"
#include <iostream>

OrginalMonster::OrginalMonster(sf::Vector2f position, int index, int length, int width) :Monster(position, index,length, width)
{
}

OrginalMonster::~OrginalMonster()
{
}
//פונקציה תזוזה למפלצות הרנדומליות
void OrginalMonster::moveMonster(sf::Time deltaTime, Player& player)
{
	Monster::moveMonster(deltaTime, player);
	int s = rand() % 4;
	m_postDirection = checkDirection(Direction(s));
	checkWhichDirectionWas();
	if (std::abs(m_sprite.getPosition().x - m_positionDestination.x) <=2&&
		std::abs(m_sprite.getPosition().y - m_positionDestination.y) <=2)
	{
		m_direction = m_postDirection;
	}
	m_sprite.move(m_direction * deltaTime.asSeconds());

}
//פונקצית ציור המפלצת 
void OrginalMonster::draw(sf::RenderWindow& window)
{
	Monster::draw(window);
}
//פונקציה טיפול בהתנגשות באבן
void OrginalMonster::HandlingCollisionWithSton()
{
	updatPosition();
}


