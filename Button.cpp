#include <SFML/Graphics/Rect.hpp>

#include "FontManager.h"
#include "Button.h"

Button::Button(string text, Widget * parent)
	: Widget(parent)
{
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

void Button::update()
{
	sf::Vector2f rectSize;
	sf::FloatRect textBounds = this->_text->getLocalBounds();

	this->_text->setPosition(Button::hPadding / 2 - textBounds.left, Button::vPadding / 2 - textBounds.top);

	rectSize.x = textBounds.width + Button::hPadding;
	rectSize.y = textBounds.height + Button::vPadding;

	this->_rect->setSize(rectSize);

	this->_text->setColor(sf::Color::Black);
	if (this->getFocus())
	{
		this->_text->setColor(sf::Color::Red);
	}
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();

	target.draw(*this->_rect, states);
	target.draw(*this->_text, states);
}

void Button::focusChanged()
{
	this->update();
}