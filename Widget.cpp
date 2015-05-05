#include "Widget.h"

Widget::Widget(Widget * parent)
	: _childs(),
	_parent(parent),
	_focus(false),
	_callbacks()
{
	if (this->_parent)
	{
		this->_parent->addChild(this);
	}
}

Widget::~Widget()
{
	this->_parent->removeChild(this);
}

void Widget::setParent(Widget * parent)
{
	if (this->_parent)
	{
		this->_parent->removeChild(this);
	}
	this->_parent = parent;
	if (this->_parent)
	{
		this->_parent->addChild(this);
	}
}

void Widget::setFocus(bool focus)
{
	if (focus != this->_focus)
	{
		this->_focus = focus;
		this->focusChanged();

		if (this->_focus)
		{
			this->emit(Widget::Event::Focus);
		}
		else
		{
			this->emit(Widget::Event::Blur);
		}
	}
}

bool Widget::getFocus() const
{
	return this->_focus;
}

void Widget::bind(Widget::Event event, ICallback * callback)
{
	this->_callbacks[event].push_back(callback);
}

void Widget::on(const sf::Event & event)
{
	if (!this->handleEvent(event))
	{
		vector<Widget *>::iterator it = this->_childs.begin();
		vector<Widget *>::iterator end = this->_childs.end();

		while (it != end)
		{
			(*it)->on(event);
			++it;
		}
	}
}

void Widget::addChild(Widget * child)
{
	this->_childs.push_back(child);
}

void Widget::removeChild(Widget * child)
{
	vector<Widget *>::const_iterator it = this->_childs.cbegin();
	vector<Widget *>::const_iterator end = this->_childs.cend();

	while (it != end)
	{
		if (*it == child)
		{
			this->_childs.erase(it);
			return;
		}

		++it;
	}
}

void Widget::emit(Widget::Event event)
{
	if (this->_callbacks.count(event))
	{
		vector<ICallback *>::iterator it = this->_callbacks[event].begin();
		vector<ICallback *>::iterator end = this->_callbacks[event].end();

		while (it != end)
		{
			(**it)();
			++it;
		}
	}
}

void Widget::focusChanged()
{

}

bool Widget::handleEvent(const sf::Event & event)
{
	return false;
}