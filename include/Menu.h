#pragma once
#include "resourc.h"
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Button.h"
#include "ButtonClose.h"
#include "ButtonStart.h"
#include <math.h>
class Menu
{
public:
	Menu();
	~Menu();

    void draw(sf::RenderWindow& window) const;

	bool isRange(sf::Vector2f location, sf::RenderWindow& window);



private:
	std::vector<Button*> m_vectorButton;
	sf::Sprite m_sprite;
	Button m_button;
};
