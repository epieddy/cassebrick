#ifndef __FOCUSABLE_GROUP_H__
# define __FOCUSABLE_GROUP_H__

#include <vector>

#include "Widget.h"

using namespace std;

class FocusableGroup : public Widget
{
public:
	FocusableGroup(Widget * parent);

	void		addItem(Widget * item);
	Widget *	currentItem();
	void		next();
	void		prev();
	void		activate(int index);

protected:
	void	focusChanged();

private:
	vector<Widget *>	_items;
	int					_index;
};

#endif // !__FOCUSABLE_GROUP_H__
