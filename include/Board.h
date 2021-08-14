#pragma once
class Controller;
class Level;
#include "resourc.h"
#include <vector>
#include "Static.h"
#include "Daimond.h"
#include "Wall.h"
#include "Player.h"
#include "Monster.h"
#include "AdditionPoint.h"
#include "AdditionSton.h"
#include "IncreaseTime.h"
#include "Gift.h"
#include "Ston.h"
#include "Const.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>       /* floor */

using std::ifstream;

class Board
{
public:
	Board();
	~Board();
	void readLevel(Level& level, Player& player, bool& win);
	void checkChar(int x, int y, char p, Level& level, Player& player);

	void randGigt(sf::Vector2f position, int length, int width, int x);
	

	void draw(sf::RenderWindow& window) const;
	Static* getUnmovables(int i, int j);
	void DeleteObject(sf::Vector2f position, sf::FloatRect rectObj);
	

	int getLevel();
	int getSumDimond();
	void updateCursor();
	void deleteVector();
	void getStartPosition();
	//void checkChar(int x, int y,char p,Level& level, Player& player);

protected:
	std::fstream m_file;
	std::vector<std::vector<Static*>> m_vectorStatic;
	std::streamoff m_startLocetion;
	int m_row;
	int m_col;
	int m_level;
	int m_SumHowDimond;
};
