#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "resourc.h"
#include "Monster.h"
#include "Const.h"
#include "SmartMonster.h"
#include "OrginalMonster.h"
//#include "Player.h"
#include "Board.h"
#include "InformationDisplay.h"
#include <ctime>
#include <thread>
#include <SFML/Audio.hpp>

class Level
{
public:
	Level();
	~Level();
	
	void runLevel(sf::RenderWindow& window, bool& m_gameOver, Player& player);
	void moveMonster(sf::Time deltaTime, Player& player);
	void sortMonster(sf::Vector2f position, float length, float width);
	void draw(sf::RenderWindow& window)const;
	void collision(Player& player);
	void CollisionUnmovablesWithMonster();

	void CollisionUnmovables(Player& player);
	void collisionBetweenMonsterToPlayer(Player& player);

	void chackPlay(Player& player, bool& gameOver, bool& youWin, sf::RenderWindow& window);

	bool isGameOver(sf::RenderWindow& window, bool& m_gameOver, Player& player);
	void SetUpTextur(int index, sf::RenderWindow& window);
protected:
	Board m_board;
	InformationDisplay m_informationDisplay;
	sf::Vector2f m_startPlayer;
	std::vector<Monster*> m_vectorMonster;
};
