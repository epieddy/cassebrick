#include "FocusableGroup.h"

FocusableGroup::FocusableGroup()
	: _items(),
	_index(0)
{

}

void FocusableGroup::addItem(Focusable * item)
{
	this->_items.push_back(item);
	item->setFocus(false);
}

Focusable * FocusableGroup::currentItem()
{
	if (this->_items.empty())
	{
		return NULL;
	}

	return this->_items[this->_index];
}

void FocusableGroup::next()
{
	if (this->_items.empty() || !this->getFocus())
	{
		return;
	}

	this->_items[this->_index]->setFocus(false);
	++this->_index;

	if (this->_index >= (int) this->_items.size())
	{
		this->_index = 0;
	}
	this->_items[this->_index]->setFocus(true);
}

void FocusableGroup::prev()
{
	if (this->_items.empty() || !this->getFocus())
	{
		return;
	}

	this->_items[this->_index]->setFocus(false);
	--this->_index;

	if (this->_index < 0)
	{
		this->_index = this->_items.size() - 1;
	}
	this->_items[this->_index]->setFocus(true);
}

void FocusableGroup::activate(int index)
{
	if (this->_items.empty())
	{
		return;
	}

	this->_items[this->_index]->setFocus(false);
	
	this->_index = index;

	if (this->_index < 0 || this->_index >= (int) this->_items.size())
	{
		this->_index = 0;
	}

	this->_items[this->_index]->setFocus(true);
}

void FocusableGroup::focusChanged(bool focus)
{
	if (this->_items.empty())
	{
		return;
	}

	this->_items[this->_index]->setFocus(focus);
}