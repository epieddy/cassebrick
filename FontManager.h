#ifndef __FONT_MANAGER_H__
# define __FONT_MANAGER_H__

#include <string>
#include <map>
#include <SFML/Graphics/Font.hpp>

using namespace std;

class FontManager
{
public:
	bool				init();
	const sf::Font &	font(string fontName);

public:
	static FontManager *	get();

private:
	FontManager() {}

private:
	map<string, sf::Font *>	_fonts;

private:
	static FontManager *	_instance;
};

#endif // !__FONT_MANAGER_H__