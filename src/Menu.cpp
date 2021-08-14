#include "Menu.h"

Menu::Menu() :m_sprite(resourc::instance().m_image[background])
{
	auto newSprite = m_sprite.getTexture();
	auto size = newSprite->getSize();
	sf::Vector2f position;
	position.x = Width / 3;
	position.y = Length / 3;
	m_sprite.scale(Width * 1.00f /size.x, Length * 1.00f /size.y);
	m_vectorButton.push_back(new (std::nothrow) ButtonStart(resourc::instance().m_image[start],sf::Vector2f(position.x,position.y),floor(2*Width/15),floor(2*Length/15)));
	m_vectorButton.push_back(new (std::nothrow) ButtonClose(resourc::instance().m_image[exitGame], sf::Vector2f(position.x, position.y = 1.5*position.y),floor( 2* Width /15),floor(2* Length /15)));
	
}

Menu::~Menu()
{
	m_vectorButton.clear();
}
//פונקצית ציור הכפתורים
void Menu::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
	for (int i = 0; i < m_vectorButton.size(); i++)
	{
		m_vectorButton[i]->draw(window);
	}
}


//בדיקת טווח הלחיצה של הכפתורים
bool Menu::isRange(sf::Vector2f location, sf::RenderWindow& window)
{
	bool start = true;
	for (auto Button : m_vectorButton)
	{
		if (Button->check(location))
		{
			Button->endelClick(window,start);
			if(start)
			return true;
		}
		
	}
	return false;
 }