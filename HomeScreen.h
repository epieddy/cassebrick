#ifndef __HOME_SCREEN_H__
# define __HOME_SCREEN_H__

#include "Screen.h"
#include "Widget.h"
#include "Button.h"
#include "FocusableGroup.h"

class Application;

class HomeScreen : public Screen, public Widget
{
public:
	HomeScreen(Application * app);

	void			show();
	void			hide();
	//bool			handleEvent(const sf::Event & event);
	void			render(sf::RenderTarget & target);
	const string	name();

	void			exit();

private:
	Button *			_buttonStart;
	Button *			_buttonExit;
	FocusableGroup *	_group;
};

#endif // !__HOME_SCREEN_H__
