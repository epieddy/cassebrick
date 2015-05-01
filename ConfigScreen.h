#ifndef __CONFIG_SCREEN_H__
# define __CONFIG_SCREEN_H__

#include "Screen.h"

class Application;

class ConfigScreen : public Screen
{
public:
	ConfigScreen(Application * app);

	void			show();
	void			hide();
	void			handleEvent(const sf::Event & event);
	void			render(sf::RenderTarget & target);
	const string	name();
};

#endif // !__CONFIG_SCREEN_H__
