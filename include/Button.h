#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Const.h"

class Button
{
public:

	Button(sf::Texture& image,sf::Vector2f position ,int width,int length);
	Button() = default;
	~Button();
	virtual bool check(sf::Vector2f position)const;
	
	virtual void endelClick(sf::RenderWindow& window,bool& start)const;

	virtual void draw(sf::RenderWindow& window)const;
protected:
	sf::Vector2u m_size;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	
};

