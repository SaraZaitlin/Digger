#include "Monster.h"



Monster::Monster(sf::Vector2f position, int index, int length, int width) : Dynamic( position,index, length, width)
{
}

Monster::~Monster()
{
}

//פונקצית תזוזה מפלצות
void Monster::moveMonster(sf::Time deltaTime,Player& player)
{
	m_prevPosition = m_sprite.getPosition();
}
//פונקציית התנגשות מפלצת במתנות
void Monster::HandlingCollisionWithSton()
{

}
//פונקציה המעדכנת את המיקום ההתחלתי כאשר נפגשים מפלצת ושחקן
void Monster::HandlingCollision()
{
	m_sprite.setPosition(m_startPosition);
}
//פונקציה המציירת את המפלצות
void Monster::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//פונקציה המחזירה את הכיוון של המפלצות
sf::Vector2f Monster::checkDirection(int postDirection)
{
	switch (postDirection)
	{
	case left:
		return {-SpeedMonster,0};
	case right:
		return  { SpeedMonster,0};
	case up:
		return {0,-SpeedMonster };
	case dawn:
		return {0,SpeedMonster };
    }
}


