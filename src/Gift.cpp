#include "Gift.h"
#include "Board.h"
Gift::Gift(sf::Vector2f position, int index, int length, int width) :Static(position,index,length, width)
{
}

Gift::~Gift()
{
}
//פונקציית התנגשות שחקן במתנה
void Gift::collide(Player& player, Board& board)
{
	board.DeleteObject(m_sprite.getPosition(), getRectangel());

}
//פונקצית התנגשות מפלצת במתנה או בסטטים
void Gift::collide(Monster* monster)
{
}


