#include <SFML/Window/Event.hpp>

#include "Application.h"
#include "HomeScreen.h"
#include "ConfigScreen.h"
#include "FontManager.h"
#include "SoundManager.h"


Application::Application()
{
	Screen *	screen;

	FontManager::get()->init();
	SoundManager::get()->init();

	this->_window = new sf::RenderWindow(sf::VideoMode(600, 800), "Casse Brick", sf::Style::Titlebar | sf::Style::Close);
	this->_window->setFramerateLimit(30);

	screen = new HomeScreen(this);
	this->_screens[screen->name()] = screen;

	screen = new ConfigScreen(this);
	this->_screens[screen->name()] = screen;

	this->_currentScreen = this->_screens["HomeScreen"];
	this->_currentScreen->show();
}

Application::~Application()
{
	delete this->_window;
}

int Application::run()
{
	sf::Event event;

	while (this->_window->isOpen())
	{
		while (this->_window->pollEvent(event))
		{
			this->_currentScreen->handleEvent(event);
		}

		this->_window->clear();
		this->_currentScreen->render(*this->_window);
		this->_window->display();
	}

	return EXIT_SUCCESS;
}

void Application::close()
{
	this->_currentScreen->hide();
	this->_window->close();
}

bool Application::switchScreen(const string screenName)
{
	if (this->_screens.count(screenName) == 0)
	{
		return false;
	}

	this->_currentScreen->hide();
	this->_currentScreen = this->_screens[screenName];
	this->_currentScreen->show();

	return true;
}
