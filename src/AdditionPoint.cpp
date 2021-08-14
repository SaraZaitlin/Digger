#include "AdditionPoint.h"
#include "Board.h"
#include "Player.h"


AdditionPoint::AdditionPoint(sf::Vector2f position, int index, int length, int width) :Gift( position, index, length, width)
{
}

AdditionPoint::~AdditionPoint()
{

}

void AdditionPoint::collide(Player& player, Board& board)
{
	if (checkCollide(player))
	{
		Gift::collide(player, board);
		player.updatPoint(15);
	}
}

void AdditionPoint::collide(Monster* monster)
{
}




