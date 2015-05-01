#include <SFML/System/Time.hpp>

#include "Application.h"
#include "HomeScreen.h"
#include "FontManager.h"

HomeScreen::HomeScreen(Application * app) :
Screen(app)
{
	this->_button = new Button("test");
	this->_button->move(50, 50);
}

void HomeScreen::show()
{

}

void HomeScreen::hide()
{

}

void HomeScreen::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::Closed)
	{
		this->_app->close();
	}
	else if (event.type == sf::Event::KeyPressed)
	{
		this->_app->switchScreen("ConfigScreen");
	}
}

void HomeScreen::render(sf::RenderTarget & target)
{
	target.clear(sf::Color::White);

	sf::Time time = this->_clock.getElapsedTime();
	this->_button->setRotation(time.asSeconds() * 5);

	target.draw(*this->_button);
}

const string HomeScreen::name()
{
	return "HomeScreen";
}