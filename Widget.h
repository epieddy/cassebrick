#ifndef __WIDGET_H__
# define __WIDGET_H__

#include <vector>
#include <map>
#include <SFML/Window/Event.hpp>

#include "Callback.h"

using namespace std;

class Widget
{

public:
	enum Event
	{
		Focus,
		Blur,
		Submit
	};

public:
	Widget(Widget * parent = 0);
	virtual ~Widget();

public:
	void setParent(Widget * parent);
	void setFocus(bool focus);
	bool getFocus() const;
	void bind(Widget::Event event, ICallback * callback);
	void on(const sf::Event & event);

protected:
	void addChild(Widget * child);
	void removeChild(Widget * child);
	void emit(Widget::Event event);

// All these method can be overriden by a child class.
protected:
	virtual void focusChanged();
	virtual bool handleEvent(const sf::Event & event);

private:
	vector<Widget *>							_childs;
	Widget *									_parent;
	bool										_focus;
	map<Widget::Event, vector<ICallback *> >	_callbacks;
};

#endif // !__WIDGET_H__
