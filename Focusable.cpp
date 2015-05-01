#include "Focusable.h"

Focusable::Focusable()
	: _focus(false)
{

}

void Focusable::setFocus(bool focus)
{
	this->_focus = focus;
	this->focusChanged(focus);
}

bool Focusable::getFocus() const
{
	return this->_focus;
}