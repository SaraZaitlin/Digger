#include "Controller.h"
//constractor
Controller::Controller() : m_window(sf::VideoMode(Width,Length), ""),m_menu(), m_gameOver(true)
{

}
//distractor
Controller::~Controller()
{
}
//פונקציה שממנה רץ ומתנהל כל המשחק
void Controller::run()
{
	
	while (m_window.isOpen())
	{
		m_window.clear();
		m_menu.draw(m_window);
		m_window.display();
		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				while(m_menu.isRange(location, m_window)&&m_gameOver==true)
				{
					m_level.runLevel(m_window, m_gameOver,m_player);
				}
				break;
			}
			}
			m_gameOver = true;
		}
	}
	

}


