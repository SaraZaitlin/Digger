#include "GameObject.h"

GameObject::GameObject(sf::Vector2f position, int index, int length, int width) :m_sprite(resourc::instance().m_image[index])
{
	//m_sprite.setTexture(image);
	m_sprite.scale(width * 1.00f / m_sprite.getTexture()->getSize().x, length * 1.00f / m_sprite.getTexture()->getSize().y);
	m_sprite.setPosition(position);
}

GameObject::~GameObject()
{
}

//פונקציה המחזירה את המלבן החוסם
sf::FloatRect GameObject::getRectangel()
{
	return m_sprite.getGlobalBounds();
}
