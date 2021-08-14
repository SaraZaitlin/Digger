#include "AdditionSton.h"
#include "Player.h"
#include "Board.h"
AdditionSton::AdditionSton(sf::Vector2f position, int index, int length, int width) :Gift( position, index, length, width)
{
}

AdditionSton::~AdditionSton()
{
}
void AdditionSton::collide(Monster* monster)
{

}

void AdditionSton::collide(Player& player, Board& board)
{
	if (checkCollide(player))
	{
		Gift::collide(player, board);
		player.updatSton(1);
	}
}
