#ifndef __HOME_SCREEN_H__
# define __HOME_SCREEN_H__

#include "Screen.h"
#include "Button.h"
#include "FocusableGroup.h"

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
	Button *	_button2;
	Button *	_button3;
	FocusableGroup *	_group;
	FocusableGroup *	_group2;
};

#endif // !__HOME_SCREEN_H__
