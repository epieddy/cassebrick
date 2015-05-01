#include <SFML/System/Time.hpp>

#include "Application.h"
#include "HomeScreen.h"
#include "FontManager.h"
#include "SoundManager.h"

HomeScreen::HomeScreen(Application * app) :
Screen(app)
{
	this->_button = new Button("Youhou !!!");
}

void HomeScreen::show()
{
	SoundManager::get()->music("night").setLoop(true);
	SoundManager::get()->music("night").play();
}

void HomeScreen::hide()
{
	SoundManager::get()->music("night").stop();
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
	target.draw(*this->_button);
}

const string HomeScreen::name()
{
	return "HomeScreen";
}