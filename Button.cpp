#include <SFML/Graphics/Rect.hpp>

#include "FontManager.h"
#include "Button.h"

Button::Button(string text)
{
	this->_focus = false;

	this->_text = new sf::Text();
	this->_rect = new sf::RectangleShape();

	this->_text->setString(text);
	this->_text->setColor(sf::Color::Black);
	this->_text->setFont(FontManager::get()->font("sansation"));

	this->_rect->setFillColor(sf::Color::Green);

	this->update();
}

Button::~Button()
{
	delete this->_text;
	delete this->_rect;
}

void Button::setFocus(bool focus)
{
	this->_focus = focus;
	this->update();
}

bool Button::getFocus() const
{
	return this->_focus;
}

void Button::update()
{
	sf::Vector2f rectSize;
	sf::FloatRect textBounds = this->_text->getLocalBounds();

	this->_text->move(Button::hPadding / 2 - textBounds.left, Button::vPadding / 2 - textBounds.top);

	rectSize.x = textBounds.width + Button::hPadding;
	rectSize.y = textBounds.height + Button::vPadding;

	this->_rect->setSize(rectSize);
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();

	target.draw(*this->_rect, states);
	target.draw(*this->_text, states);
}
