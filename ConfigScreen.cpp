#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "Application.h"
#include "ConfigScreen.h"

ConfigScreen::ConfigScreen(Application * app) :
Screen(app)
{

}

void ConfigScreen::show()
{

}

void ConfigScreen::hide()
{

}

void ConfigScreen::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::Closed)
	{
		this->_app->close();
	}
	else if (event.type == sf::Event::KeyPressed)
	{
		this->_app->switchScreen("HomeScreen");
	}
}

void ConfigScreen::render(sf::RenderTarget & target)
{
	target.clear(sf::Color::Green);

	sf::RectangleShape rect(sf::Vector2f(50, 50));
	rect.setFillColor(sf::Color::White);

	target.draw(rect);
}

const string ConfigScreen::name()
{
	return "ConfigScreen";
}