#include <SFML/System/Time.hpp>

#include "Application.h"
#include "HomeScreen.h"
#include "FontManager.h"
#include "SoundManager.h"
#include "Callback.h"

HomeScreen::HomeScreen(Application * app)
	: Screen(app),
	Widget()
{
	this->_buttonStart = new Button("Play", this);
	this->_buttonExit = new Button("Exit", this);
	this->_buttonExit->move(0, 200);

	this->_group = new FocusableGroup(this);
	this->_group->addItem(this->_buttonStart);
	this->_group->addItem(this->_buttonExit);
	this->_group->activate(0);
	this->_group->setFocus(true);

	this->_buttonExit->bind(Widget::Event::Submit, new Callback<HomeScreen>(this, &HomeScreen::exit));
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

/*void HomeScreen::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::Closed)
	{
		this->exit();
	}
	else if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Down:
			this->_group->next();
			break;
		case sf::Keyboard::Up:
			this->_group->prev();
			break;
		case sf::Keyboard::Right:
			this->_buttonExit->emit("activate");
			break;
		}

	}
}*/

void HomeScreen::render(sf::RenderTarget & target)
{
	target.clear(sf::Color::White);
	target.draw(*this->_buttonStart);
	target.draw(*this->_buttonExit);
}

const string HomeScreen::name()
{
	return "HomeScreen";
}

void HomeScreen::exit()
{
	this->_app->close();
}
