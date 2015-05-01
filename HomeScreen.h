#ifndef __HOME_SCREEN_H__
# define __HOME_SCREEN_H__

#include <SFML/System/Clock.hpp>
#include "Screen.h"
#include "Button.h"

class Application;

class HomeScreen : public Screen
{
public:
	HomeScreen(Application * app);

	void			show();
	void			hide();
	void			handleEvent(const sf::Event & event);
	void			render(sf::RenderTarget & target);
	const string	name();

private:
	Button *	_button;
	sf::Clock	_clock;
};

#endif // !__HOME_SCREEN_H__
