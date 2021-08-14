#pragma once
#include "resourc.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Player;
class Board;
class InformationDisplay
{
public:
	InformationDisplay();
	~InformationDisplay();
	void UpdatingInformationView(sf::RenderWindow& window, Player& player, Board& board, sf::Time deltaTime);
	


protected:

	sf::Sprite m_sprite;
	sf::Text m_printLevel;
	sf::Text m_printSton;
	sf::Text m_printLife;
	sf::Text m_printTime;
	sf::Text m_printPoint;


};


