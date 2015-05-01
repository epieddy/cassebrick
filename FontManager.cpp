#include "FontManager.h"

FontManager * FontManager::_instance = NULL;

bool FontManager::init()
{
	sf::Font *	font;

	font = new sf::Font();
	if (!font->loadFromFile("fonts/sansation.ttf"))
	{
		return false;
	}
	this->_fonts["sansation"] = font;

	return true;
}

const sf::Font & FontManager::font(string fontName)
{
	return *this->_fonts[fontName];
}

FontManager * FontManager::get()
{
	if (FontManager::_instance == NULL)
	{
		FontManager::_instance = new FontManager();
	}

	return FontManager::_instance;
}
