#include "Board.h"
#include "Controller.h"
#include "Level.h"



Board::Board():m_file("Board.txt"),m_level(0)//, m_SumHowDimond (0)
{

}

Board::~Board()
{
	std::cout << "des-board" << std::endl;
	for (int i = 0; i < m_vectorStatic.size(); i++)
		m_vectorStatic[i].clear();

	m_vectorStatic.clear();
}
//פונקציה הקוראת מהקובץ את השלב
void Board::readLevel(Level& level,Player& player,bool& youWin)
{
	int ston, time;
	char p;
	m_startLocetion = m_file.tellg();
	if (m_file.eof())
	{
		youWin =true;
		return;
	}
	else
	{
		m_file >> m_row>>m_col>>ston>>time;
		std::cout << m_row << m_col << std::endl;
		m_level++;
	    m_SumHowDimond = 0;
		player.updateInformationDisplay(ston, time);
		m_vectorStatic.resize(m_row);
		p = m_file.get();
		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < m_col; j++)
			{
				p = m_file.get();
				checkChar(i, j,p, level, player);
			}
			std::cout << m_vectorStatic.size();
			std::cout << " "<< std::endl;
			p = m_file.get();
		}
	   m_file.get();

	}
	//m_file.close();

}

//פונקציה שבודקת את התו ומכניסה  לווקטור את האובייקט
void Board::checkChar(int x, int y, char p,Level& level, Player& player)
{
	int length = floor(Length/m_row);
	int width = floor((Width-200)/m_col);
	std::cout << length << " " << width << std::endl;
	sf::Vector2f position;
	position.x = width *y;
	position.y = length * x;
	switch (p)
	{

	case DIAMOND:
	{
		std::cout << "DIAMOND";
		m_SumHowDimond++;
		m_vectorStatic[x].push_back(new (std::nothrow)Daimond(position,daimond, length, width));
		break;

	}
	case WALL:
	{
		std::cout  << "WALL";

		m_vectorStatic[x].push_back(new (std::nothrow)Wall(position,wall, length, width));

		break;

	}
	case MONSTER:
	{
		std::cout << "MONSTER";

		m_vectorStatic[x].push_back(nullptr);
		level.sortMonster(position, length, width);
		break;

	}
	case EmptyLocation:
	{
		std::cout << "EmptyLocation";

		m_vectorStatic[x].push_back(nullptr);
		break;

	}
	case STON:
	{
		std::cout << "STON";

		m_vectorStatic[x].push_back(new (std::nothrow)Ston(position, 
			ston, length, width));

		break;

	}
	case PLAYER:
	{
		std::cout << "PLAYER" ;

		m_vectorStatic[x].push_back(nullptr);
		player.setPosition(position);
	    player.setSize(length, width);
		break;

	}
	case GIFT:
	{
		std::cout << "GIFT" ;
		randGigt(position, length, width,x);
	}
	}
}
//פונקציה 
void Board::randGigt(sf::Vector2f position ,int length,int width,int x)
{
	switch (rand() % 3)
	{
	case 0:
	{
		m_vectorStatic[x].push_back(new (std::nothrow)AdditionPoint(position,giftpointing, length, width));
		break;
	}
	case 1:
	{
		m_vectorStatic[x].push_back(new (std::nothrow)AdditionSton(position,giftSton, length, width));
		break;
	}
	case 2:
	{
		m_vectorStatic[x].push_back(new (std::nothrow)IncreaseTime(position,giftTime, length, width));
		break;
	}

	}
}
//פונקציה המציירת את הלוח
void Board::draw(sf::RenderWindow & window) const
{
	//SetUpTextur(backgroundGame,window);
		sf::Sprite sprite;
		sprite.setPosition(0, 0);
		sprite.setTexture(resourc::instance().m_image[backgroundGame]);
		sprite.scale(Width * 1.00f / sprite.getTexture()->getSize().x, Length * 1.00f / sprite.getTexture()->getSize().y);
		window.draw(sprite);
	
		for (int i = 0; i < m_vectorStatic.size(); i++)
			for (int j = 0; j < m_vectorStatic[i].size(); j++)
				if (m_vectorStatic[i][j] != nullptr)
				{
					m_vectorStatic[i][j]->draw(window);
				}
}



//פונקציה המחזירה אוביקט מהווקטור
Static* Board::getUnmovables(int i,int j)
{

		return m_vectorStatic[i][j];
}

//פונקציה המוחקת אוביקט מהווקטור
void Board::DeleteObject(sf::Vector2f position , sf::FloatRect rectObj)
{
	delete m_vectorStatic[position.y / rectObj.height]
		[position.x / rectObj.width];
	m_vectorStatic[position.y/ rectObj.height]
		[position.x/ rectObj.width]= nullptr;
}


int Board::getLevel()
{
	return m_level;
}

int Board::getSumDimond()
{
	return m_SumHowDimond;
}

//מעדכנת את הסמן לתחילת השלב
void Board::updateCursor()
{
	m_file.seekg(m_startLocetion);
	m_level--;
}
//פונקציה המשחררת את הווקטור של הסטטים
void Board::deleteVector()
{
	for (int i = 0; i < m_vectorStatic.size(); i++)
		   m_vectorStatic[i].clear();

	m_vectorStatic.clear();
}
///פונקציה שמחזירה את המיקום ההתחלתי לתחילת הקובץ
void Board::getStartPosition()
{
	m_level = 0;
	m_file.seekg(0, 0);
}
