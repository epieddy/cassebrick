#ifndef __FOCUSABLE_GROUP_H__
# define __FOCUSABLE_GROUP_H__

#include <vector>

#include "Focusable.h"

using namespace std;

class FocusableGroup : public Focusable
{
public:
	FocusableGroup();

	void		addItem(Focusable * item);
	Focusable *	currentItem();
	void		next();
	void		prev();
	void		activate(int index);

protected:
	void	focusChanged(bool focus);

private:
	vector<Focusable *>	_items;
	int					_index;
};

#endif // !__FOCUSABLE_GROUP_H__
