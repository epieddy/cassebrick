#ifndef __SCREEN_H__
# define __SCREEN_H__

#include <string>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>

using namespace std;

class Application;

class Screen
{
public:
	Screen(Application * app);

	virtual void			show() = 0;
	virtual void			hide() = 0;
	virtual void			handleEvent(const sf::Event & event) = 0;
	virtual void			render(sf::RenderTarget & target) = 0;
	virtual const string	name() = 0;

protected:
	Application *	_app;
};


#endif // !__SCREEN_H__