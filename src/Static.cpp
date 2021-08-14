#include "Static.h"
#include "Player.h"
#include "Board.h"
#include "Monster.h"

Static::Static(sf::Vector2f position, int index, int length, int width) :GameObject(position,index, length, width)
{
}

Static::~Static ()
{
}
//ציור האוביקטים הסטטים
void Static::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//פונקציה המחזירה את המיקום הנוכחי
sf::Vector2f Static::getPosition()
{

	return m_sprite.getPosition();

}

//פונקציה הבודקת אם השחקן הגיע  לאמצע המשבצת ורק אז מאפשר לאכול
bool Static::checkCollide(Player& player)
{
	if (std::abs(player.getPosition().x - m_sprite.getPosition().x) <= player.getRectangel().height / 3 &&
		std::abs(player.getPosition().y - m_sprite.getPosition().y) <= player.getRectangel().width / 3)
		return true;
	return false;
}
