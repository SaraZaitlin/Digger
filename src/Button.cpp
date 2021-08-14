#include "Button.h"


Button::Button(sf::Texture& image, sf::Vector2f position, int width, int length) :m_texture(image)
{
	m_sprite.setTexture(m_texture);
	auto newSprite = m_sprite.getTexture();
	m_size = newSprite->getSize();
	m_sprite.scale(width* 1.00f /m_size.x, length* 1.00f /m_size.y);
	m_sprite.setPosition(position);
}


Button::~Button()
{
}
//פונקציה שבודקת אם היתה לחיצה בכפתורים
bool Button::check(sf::Vector2f position)const
{
	auto rectangle = sf::RectangleShape({2 * Width * 1.00f / 15,2 * Length * 1.00f / 15 });
	rectangle.setPosition(m_sprite.getPosition());
	
	return rectangle.getGlobalBounds().contains(position);
}

//פונקציה שתופסת לחיצת עכבר
void Button::endelClick(sf::RenderWindow& m_window,bool& start)const
{
}

//פונקציית ציור האובייקטים
void Button::draw(sf::RenderWindow& window) const
{
	//window.draw(m_sprite);
	
}
