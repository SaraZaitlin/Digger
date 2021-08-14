#include "Ston.h"
#include "Player.h"
#include "Board.h"
Ston::Ston(sf::Vector2f position, int index, int length, int width):Static( position, index, length,width)
{
}

Ston::~Ston()
{
}
//פונקציה התנגשות שחקן  עם אבן
void Ston::collide(Player& player, Board& board)
{
	if (player.updatSton(-1))
		board.DeleteObject(m_sprite.getPosition(), getRectangel());
	else
	player.updatPosition();
}
//פונקציה התנגשות של מפלצת עם אבן 
void Ston::collide(Monster* monster)
{
	monster->HandlingCollisionWithSton();
}
