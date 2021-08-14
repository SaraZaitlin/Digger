#include "Daimond.h"
#include "Player.h"
#include "Board.h"
Daimond::Daimond(sf::Vector2f position, int index, int length, int Width) : Static( position, index, length, Width)
{
}
//distractor
Daimond::~Daimond()
{
} 
  
//������� ������� ���� MONSTER
void Daimond::collide(Monster* monster)
{
}
///������� ������� ���� ����� �����
void Daimond::collide(Player& player, Board& board)
{
	if (checkCollide(player))
	{
		player.updatSumDaimond();
		board.DeleteObject(m_sprite.getPosition(), getRectangel());
	}
}


