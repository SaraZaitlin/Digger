#include "Wall.h"
#include "Player.h"
#include "Monster.h"
Wall::Wall(sf::Vector2f position, int index, int length, int width):Static(position, index, length,width)
{
}

Wall::~Wall()
{
}
//פונקציה התנגשות של שחקן עם אבן 

void Wall::collide(Player& player, Board& board)
{
	player.updatPosition();
}
//פונקציה התנגשות של מפלצת עם קיר 

void Wall::collide(Monster* monster)
{
	monster->updatPosition();
}


