#ifndef __CALLBACK_H__
# define __CALLBACK_H__

class ICallback
{
public:
	virtual void operator()() = 0;
};

template<class T>
class Callback : public ICallback
{
public:
	Callback(T * instance, void(T::*method)());
	void operator()();

private:
	T *		_instance;
	void(T::*_method)();
};

template<class T>
Callback<T>::Callback(T * instance, void(T::*method)())
	: _instance(instance),
	_method(method)
{}

template<class T>
void Callback<T>::operator()()
{
	(*this->_instance.*this->_method)();
}

#endif // !__CALLBACK_H__
