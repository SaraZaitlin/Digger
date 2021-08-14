#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class resourc
{
public:
	~resourc();
	static resourc& instance();
	sf::Font& getFont();
	sf::Music m_music;
	std::vector<sf::Texture> m_image;
private:
	resourc();
	resourc(const resourc&)=default;
	void pushTexturInVectur();
	sf::Font m_font;


};
