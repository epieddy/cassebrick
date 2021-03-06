#ifndef __BUTTON_H__
# define __BUTTON_H__

#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Widget.h"

using namespace std;

class Button : public sf::Drawable, public sf::Transformable, public Widget
{
public:
	Button(string text, Widget * parent);
	~Button();

protected:
	void update();
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void focusChanged();

private:
	sf::Text *				_text;
	sf::RectangleShape *	_rect;

private:
	const float vPadding = 20;
	const float hPadding = 20;
};

#endif // !__BUTTON_H__
