#include <SFML/System/Time.hpp>

#include "Application.h"
#include "HomeScreen.h"
#include "FontManager.h"
#include "SoundManager.h"

HomeScreen::HomeScreen(Application * app) :
Screen(app)
{
	this->_button = new Button("Youhou !!!");
	this->_button2 = new Button("Test");
	this->_button2->move(0, 200);

	this->_button3 = new Button("Toto");
	this->_button3->move(200, 100);

	this->_group = new FocusableGroup();
	this->_group->addItem(this->_button);
	this->_group->addItem(this->_button2);
	this->_group->activate(0);

	this->_group2 = new FocusableGroup();
	this->_group2->addItem(this->_group);
	this->_group2->addItem(this->_button3);
	this->_group2->activate(0);
	this->_group2->setFocus(true);
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
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			this->_app->switchScreen("ConfigScreen");
			break;
		case sf::Keyboard::Down:
			this->_group->next();
			break;
		case sf::Keyboard::Up:
			this->_group->prev();
			break;
		case sf::Keyboard::Right:
			this->_group2->next();
			break;
		case sf::Keyboard::Left:
			this->_group2->prev();
			break;
		}

	}
}

void HomeScreen::render(sf::RenderTarget & target)
{
	target.clear(sf::Color::White);
	target.draw(*this->_button);
	target.draw(*this->_button2);
	target.draw(*this->_button3);
}

const string HomeScreen::name()
{
	return "HomeScreen";
}