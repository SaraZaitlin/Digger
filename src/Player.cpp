 #include "Player.h"
#include "Const.h"
#include "Monster.h"
#include "Board.h"
#include <iostream>
#include <cmath>
Player::Player(sf::Vector2f position, int index, int length, int width): Dynamic( position, index, length, width)
{

}

Player::~Player()
{
}
//מעדכנת את המשתנים בשביל התצוגת מידע
void Player::updateInformationDisplay(int ston,int time)
{
	m_maxSton = ston;
	m_time = time;
	m_sumDaimond = 0;

}
//פונקציה המציירת את השחקן
void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//פונקציה המחזירה את המיקום הנוכחי
sf::Vector2f Player::getPosition()
{
	return m_sprite.getPosition();
}

//פונקציה טיפול בהתנגשות
bool Player::HandlingCollision()
{
	m_life -= 1;
	m_sprite.setPosition(m_startPosition);
	return (m_life >= 0);
}

//מחיקת אוביקטים שנאכלים
void Player::DeleteObject(Board& board)
{
	
	m_sprite.getGlobalBounds();

}
//פונקציה המורידה חיים לשחקן
void Player::updatLife()
{
	m_life--;
}
//פונקציה המעדכנת את מספר האבנים שנישאר לאכל 
bool Player::updatSton(int num)
{
	if (m_maxSton > 0)
	{
		m_maxSton += num;
		return true;
	}
	return false;
}
//פונקציה המעדכנת את מספר האבנים שאכל 
void Player::updatSumDaimond()
{
	m_sumDaimond += 1;
	m_point += 15;
}
//מוסיפה זמן
void Player::updatIncreaseTime()
{
	m_time += 60;
}
//מוסיפה נקודות
void Player::updatPoint(int num)
{

	m_point += num;
}



//פונקציה המעדבנת את המיקום
void Player::setPosition(sf::Vector2f position)
{
	m_positionDestination = position;
	m_sprite.setPosition(position);
	m_startPosition = position;
}
//פונקציה המעדכנת את הגודל והתמונה
void Player::setSize(int length, int width)
{
	m_sprite.setTexture(resourc::instance().m_image[player]);
	auto newSprite = m_sprite.getTexture();
	auto size = newSprite->getSize();
	m_sprite.setScale(width * 1.00f / size.x, length * 1.00f / size.y);
	Bootfeatures();
}
//פונקציה המאתחלת את מספר החיים
void Player::Bootfeatures()
{
	if(m_isStartLevel==false)
	m_life = 3;
}

//פונקציה הבודקת את הלחיצה לאיזה כיוון השחקן צריך ללכת
 void Player::setDirection(sf::Keyboard::Key key)
{
	 switch (key) {
	 case sf::Keyboard::Key::Space:
		 checkWhichDirectionWas();
		 m_postDirection= sf::Vector2f(0, 0);
		 break;
	 case sf::Keyboard::Key::Left:
		 checkWhichDirectionWas();
		 m_postDirection= sf::Vector2f(-Speed, 0);
			 break; 
	 case sf::Keyboard::Key::Right:
		 checkWhichDirectionWas();
			 m_postDirection = sf::Vector2f(Speed, 0);
		 break;
	 case sf::Keyboard::Key::Up:
		 checkWhichDirectionWas();
		 m_postDirection = sf::Vector2f(0, -Speed);
		 break;
	 case sf::Keyboard::Key::Down:
		 checkWhichDirectionWas();

		m_postDirection = sf::Vector2f(0, Speed);

		 break;
	 }
}
 //פונקציה המחשבת את המיקום הבא של השחקן
 //מהירות * זמן = דרך
 void Player::move(sf::Time deltaTime)
 {

	 m_prevPosition = (m_sprite.getPosition());
	 if (std::abs(m_sprite.getPosition().x - m_positionDestination.x)<=1&&
	 std::abs(m_sprite.getPosition().y - m_positionDestination.y )<=1)
		 m_direction = m_postDirection;

	 m_sprite.move(m_direction * deltaTime.asSeconds());
	 if (!checkLimit(m_sprite.getPosition()))
		 updatPosition();
 }




 //פונקציה המחזירה את מספר האבנים שנישאר לשחקן לאכול
 int Player::getMaxSton()
 {
	 return m_maxSton;
 }
 //פונקציה הבודקת אם נישאר זמן
 bool Player::checkTime()
 {
	 if (m_time <= 0)
	 {
		 m_isStartLevel = true;
		 m_life--;
		 return false;
	 }
	 m_isStartLevel = false;

	 return true;

 }
 //פונקציה המחשבת את הזמן שנישאר
 int Player::getTime(sf::Time deltaTime)
 {
	 return m_time= m_time- deltaTime.asSeconds();
 }

 int Player::getLife()
 {
	 return m_life;
 }

 int Player::getPoint()
 {
	 return m_point;
 }

 int Player::getDaimond()
 {
	 //std::cout << m_sumDaimond <<std:: endl;
	 return m_sumDaimond;
 }


