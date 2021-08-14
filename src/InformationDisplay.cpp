#include "InformationDisplay.h"
#include "Player.h"
#include "Board.h"





InformationDisplay::~InformationDisplay()
{
}

InformationDisplay::InformationDisplay()
{
	m_sprite.scale(100,800);
	m_sprite.setPosition(800,0);

	m_printLevel = sf::Text("LIFE:", resourc::instance().getFont());
	m_printLife = sf::Text("POINT:", resourc::instance().getFont());
	m_printPoint = sf::Text("STON:", resourc::instance().getFont());
	m_printTime = sf::Text("TIME:", resourc::instance().getFont());
	m_printSton = sf::Text("LEVEL:", resourc::instance().getFont());

	auto red = sf::Color::Red;
	m_printLife.setColor(red);
	m_printPoint.setColor(red);
	m_printSton.setColor(red);
	m_printTime.setColor(red);
	m_printLevel.setColor(red);

	m_printLife.setPosition({800,100});
	m_printPoint.setPosition({800,200});
	m_printSton.setPosition({800,300});
	m_printTime.setPosition({800,400});
	m_printLevel.setPosition({800,500});


	m_printLife.setCharacterSize(35);
	m_printPoint.setCharacterSize(35);
	m_printSton.setCharacterSize(35);
	m_printTime.setCharacterSize(35);
	m_printLevel.setCharacterSize(35);

}

//פונקצייה שאחראית על תצוגת המידע

void InformationDisplay::UpdatingInformationView(sf::RenderWindow& window, Player& player, Board& board, sf::Time deltaTime)
{
	auto text = sf::Text(std::to_string(player.getPoint()), resourc::instance().getFont());
	text.setPosition(915, 100);
	text.setCharacterSize(35);
	window.draw(m_printPoint);
	window.draw(text);


	text = sf::Text(std::to_string(player.getMaxSton()), resourc::instance().getFont());
	text.setPosition(910, 200);
	text.setCharacterSize(35);
	window.draw(m_printSton);
	window.draw(text);

	text = sf::Text(std::to_string(board.getLevel()), resourc::instance().getFont());
	text.setPosition(910, 300);
	text.setCharacterSize(35);
	window.draw(m_printLevel);
	window.draw(text);

	text = sf::Text(std::to_string(player.getTime(deltaTime)), resourc::instance().getFont());
	text.setPosition(910, 400);
	text.setCharacterSize(35);
	window.draw(m_printTime);
	window.draw(text);

	text = sf::Text(std::to_string(player.getLife()), resourc::instance().getFont());
	text.setPosition(910, 500);
	text.setCharacterSize(35);
	window.draw(m_printLife);
	window.draw(text);
	

}