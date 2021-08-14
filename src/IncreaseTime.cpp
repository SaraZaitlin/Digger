#include "IncreaseTime.h"
#include "Board.h"
#include "Player.h"

IncreaseTime::IncreaseTime(sf::Vector2f position, int index, int length, int width) :Gift(position, index, length, width)
{
}

IncreaseTime::~IncreaseTime()
{
}
//������� ������� �� ���� �� ���� 

void IncreaseTime::collide(Player& player, Board& board)
{
	if (checkCollide(player))
	{
		Gift::collide(player, board);
		player.updatIncreaseTime();
	}
}
//������� ������� �� ����� �� ���� 

void IncreaseTime::collide(Monster* monster)
{
}

