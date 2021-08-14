#pragma once
#include "Button.h"
class ButtonClose:public Button
{
public:
	ButtonClose(sf::Texture& image, sf::Vector2f position,int width, int length);
	~ButtonClose();
	virtual void draw(sf::RenderWindow& window) const;
	virtual void endelClick(sf::RenderWindow& window,bool& start)const;
protected:

};
