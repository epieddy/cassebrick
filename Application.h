#ifndef __APPLICATION_H__
# define __APPLICATION_H__

#include <map>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Screen.h"

using namespace std;

class Application
{

public:

	Application();
	~Application();

	int		run();
	void	close();
	bool	switchScreen(const string screenName);

private:
	sf::RenderWindow *		_window;
	Screen *				_currentScreen;
	map<string, Screen *>	_screens;
};

#endif // !__APPLICATION_H__
