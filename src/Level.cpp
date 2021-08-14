#include "Level.h"

Level::Level() :m_board()
{

}
Level::~Level()
{
	std::cout << "des-level" << std::endl;
	m_vectorMonster.clear();
}

//פונקציה אשר מנהלת את המשחק
void Level::runLevel(sf::RenderWindow& window,bool& gameOver,Player& player)
{
	bool youWin = false;
		sf::Clock clock;
		sf::Event event;
		window.clear();
		resourc::instance().m_music.play();
		m_board.readLevel(*this, player, youWin);
		while (m_board.getSumDimond() != player.getDaimond()
			&& isGameOver(window, gameOver, player) == false && youWin == false)
		{
			auto deltaTime = clock.restart();
			window.clear();
			m_board.draw(window);
			player.draw(window);
			draw(window);//ציור המפלצות
			m_informationDisplay.UpdatingInformationView(window, player, m_board, deltaTime);
			window.display();
			for (auto event = sf::Event{}; window.pollEvent(event);)
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					player.setDirection(event.key.code);
				}
			}
			moveMonster(deltaTime, player);
			player.move(deltaTime);
			collision(player);
			if (player.checkTime() == false)
			{
				m_board.updateCursor();
				break;
			}
		}

		chackPlay(player, gameOver, youWin, window);

}
//פונקציה תזוזה מפלצות
void Level::moveMonster(sf::Time deltaTime, Player& player)
{
	for (auto monster : m_vectorMonster)
	{
		monster->moveMonster(deltaTime,player);
	}
}
//פונקציה המגרילה בתחילת המשחק את סוג המפלצת
void Level::sortMonster(sf::Vector2f position,float  length, float width)

{
	int teypMonster= rand()% 2;
	switch (teypMonster)
	{
	case 0:
	{
		m_vectorMonster.push_back(new (std::nothrow)SmartMonster( position, smartMonster, length, width));

		break;
	}
	case 1:
	{
		m_vectorMonster.push_back(new (std::nothrow)OrginalMonster( position, orginalMonster, length, width));

		break;
	}
	}
}

//פונקציה ציור המפלצות
void Level::draw(sf::RenderWindow& window)const
{
	for (int i = 0; i < m_vectorMonster.size(); i++)
		m_vectorMonster[i]->draw(window);

}

//פונקציה הבודקת את ההתנגשיות ושולחת לטיפול
void Level::collision(Player& player)
{
	CollisionUnmovables(player);

	collisionBetweenMonsterToPlayer(player);
	
	CollisionUnmovablesWithMonster();
}
//פונקציה הבודקת התנגשות של מפלצות בסטטים
void Level::CollisionUnmovablesWithMonster()
{

	for (auto monster : m_vectorMonster)
	{
     auto* Unmovables = m_board.getUnmovables((monster->getPositionDestination().y / (monster->getRectangel()).height),
		(monster->getPositionDestination().x / monster->getRectangel().width));
     if (Unmovables != nullptr)
      if (monster->getRectangel().intersects(Unmovables->getRectangel()))
           Unmovables->collide(monster);
	}
}
//פונקציה הבודקת התנגשות של שחקן בסטטים
void Level::CollisionUnmovables(Player& player)
{
	auto* Unmovables = m_board.getUnmovables((player.getPositionDestination().y / (player.getRectangel()).height),
		(player.getPositionDestination().x / player.getRectangel().width));
	if (Unmovables != nullptr)
		if (player.getRectangel().intersects(Unmovables->getRectangel()))
				Unmovables->collide(player, m_board);
}

//פונקציה התנגשות בין שחקן למפלצת
void Level::collisionBetweenMonsterToPlayer(Player& player)
{
	for (auto monster : m_vectorMonster)
	{
		if (monster != nullptr)
		{
			if (player.getRectangel().intersects(monster->getRectangel()))
			{
				//if (std::abs(player.getPosition().x - monster->getPosition().x) <= player.getRectangel().height &&
					//std::abs(player.getPosition().y - monster->getPosition().y) <= player.getRectangel().width)
				{
					player.HandlingCollision();
					for (auto monst : m_vectorMonster)
						monst->HandlingCollision();
				}
			}
		}
    }

}

// פונקציה אשר בודקת בסיום השלב את המצב ומעדכנת 
void Level::chackPlay(Player& player, bool& gameOver,bool& youWin, sf::RenderWindow& window)
{
	m_board.deleteVector();
	m_vectorMonster.clear();
	if (gameOver == false)
	{
		m_board.getStartPosition();
		player.Bootfeatures();
		return;
	}
	if (youWin == true)
	{
		SetUpTextur(win, window);
		//m_gameOver == false;
		return;
	}
	if (m_board.getSumDimond() == player.getDaimond())
		player.updatPoint(20);
}
//פונקציה סיום משחק
bool Level::isGameOver(sf::RenderWindow& window,bool& m_gameOver, Player& player)
{

	if (player.getLife() < 0)
	{
		SetUpTextur(gameOver, window);
		m_gameOver = false;
		return true;
	}
	return false;
}

//פונקציה אשר מגדירה את התמונה 
void Level::SetUpTextur(int index, sf::RenderWindow& window)
{
	window.clear();
	sf::Sprite sprite;
	sprite.setPosition(0, 0);
	sprite.setTexture(resourc::instance().m_image[index]);
	sprite.scale(Width * 1.00f / sprite.getTexture()->getSize().x, Length * 1.00f / sprite.getTexture()->getSize().y);
	window.draw(sprite);
	window.display();
	using namespace std::chrono_literals;

	std::this_thread::sleep_for(3s);

}