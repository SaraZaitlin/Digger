#include "ButtonStart.h"
//constractor
ButtonStart::ButtonStart(sf::Texture& image, sf::Vector2f position, int width, int length):Button(image,  position,  width,  length)
{
}
//distractor
ButtonStart::~ButtonStart()
{
}
//פונקצית ציור עבור כפתור כניסה
void ButtonStart::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);

}
//פונקצייה שתופסת לחיצת עכבר עבור כפתור כניסה
void ButtonStart::endelClick(sf::RenderWindow& window,bool& start)const
{
	window.clear();
}
