#include "ButtonClose.h"

ButtonClose::ButtonClose(sf::Texture& image, sf::Vector2f position, int width, int length):Button( image,  position, width,length)
{
}

ButtonClose::~ButtonClose()
{
}

//פונקציית ציור
void ButtonClose::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);

}
//פונקצית שתופסת לחיצת עכבר עבור כפתור סגירת חלון 
void ButtonClose::endelClick(sf::RenderWindow& window,bool& start)const
{
	window.close();
	start = false;
}


