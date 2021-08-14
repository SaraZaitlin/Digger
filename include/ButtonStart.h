#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>

class ButtonStart:public Button
{
public:
	ButtonStart(sf::Texture& image, sf::Vector2f position, int width, int length);
	~ButtonStart();
	virtual void draw(sf::RenderWindow& window)const;
	virtual void endelClick(sf::RenderWindow& window,bool& start)const;
protected:

};

