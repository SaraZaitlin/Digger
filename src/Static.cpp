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
//���� ��������� ������
void Static::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//������� ������� �� ������ ������
sf::Vector2f Static::getPosition()
{

	return m_sprite.getPosition();

}

//������� ������ �� ����� ����  ����� ������ ��� �� ����� �����
bool Static::checkCollide(Player& player)
{
	if (std::abs(player.getPosition().x - m_sprite.getPosition().x) <= player.getRectangel().height / 3 &&
		std::abs(player.getPosition().y - m_sprite.getPosition().y) <= player.getRectangel().width / 3)
		return true;
	return false;
}
