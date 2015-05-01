#ifndef __FOCUSABLE_H__
# define __FOCUSABLE_H__

class Focusable
{
public:
	Focusable();

	void	setFocus(bool focus);
	bool	getFocus() const;

protected:
	virtual void focusChanged(bool focus) = 0;

private:
	bool _focus;
};

#endif // !__FOCUSABLE_H__
