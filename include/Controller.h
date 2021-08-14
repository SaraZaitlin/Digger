#pragma once
#include <vector>
#include "Level.h"
#include "Monster.h"
#include "Board.h"
#include "Menu.h"
#include "Player.h"
//#include "InformationDisplay.h"
#include <SFML/Graphics.hpp>
class Controller
{
public:
	Controller();
	~Controller();
	void run();
protected:
	sf::RenderWindow m_window;
	Menu m_menu;
	Player m_player;

	//Player m_player;
	//Board m_board;
	Level m_level;
	bool m_gameOver;
};
