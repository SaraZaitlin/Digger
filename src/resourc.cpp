#include "resourc.h"
#include <iostream>
resourc::resourc()
{
	pushTexturInVectur();
}

resourc::~resourc()
{
}



// הכנסת האוביקטים לתוך הווקטור וקריאת הקבצים
void resourc::pushTexturInVectur()
{
	auto Player = sf::Texture();
	Player.loadFromFile("player.png");
	m_image.push_back(Player);

	auto OrginalMonster = sf::Texture();
	OrginalMonster.loadFromFile("orginalMonster.png");
	m_image.push_back(OrginalMonster);

	auto SmartMonster = sf::Texture();
	SmartMonster.loadFromFile("smartMonster.png");
	m_image.push_back(SmartMonster);

	auto Daimond = sf::Texture();
	Daimond.loadFromFile("diamond.png");
	m_image.push_back(Daimond);

	auto Ston = sf::Texture();
	Ston.loadFromFile("stone.png");
	m_image.push_back(Ston);

	auto Wall = sf::Texture();
	Wall.loadFromFile("wall.jpg");
	m_image.push_back(Wall);


	auto giftSton = sf::Texture();
	giftSton.loadFromFile("gift stone.png");
	m_image.push_back(giftSton);

	auto giftTime = sf::Texture();
	giftTime.loadFromFile("gift time.png");
	m_image.push_back(giftTime);

	auto giftPointing = sf::Texture();
	giftPointing.loadFromFile("gift pointiing.png");
	m_image.push_back(giftPointing);


	auto background = sf::Texture();
	background.loadFromFile("background.jpg");
	m_image.push_back(background);

	auto start = sf::Texture();
	start.loadFromFile("start.JPG");
	m_image.push_back(start);

	auto exit = sf::Texture();
	exit.loadFromFile("exit.JPG");
	m_image.push_back(exit);

	auto backgroundGame = sf::Texture();
	backgroundGame.loadFromFile("backgroundGame.jpg");
	m_image.push_back(backgroundGame);

	auto gameOver = sf::Texture();
	gameOver.loadFromFile("game over.jpg");
	m_image.push_back(gameOver);

	auto win = sf::Texture();
	win.loadFromFile("win.jpg");
	m_image.push_back(win);

	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	m_music.openFromFile("song.wav");
}

//
resourc& resourc::instance()
{
	static resourc instan;
	return instan;
}


//עבור התצוגת מידע
sf::Font& resourc::getFont()
{
	return m_font;
}

