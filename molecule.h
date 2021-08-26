/*!
\file molecule.cpp
\brief This is a template class, containing elements of data
*/
#pragma once

// class template:
template <typename T, typename U, typename X>
class molecule {
public:
	molecule(T arg, U arg2, X arg3)
	{
		element = arg;
		element2 = arg2;
		element3 = arg3;
	}
	T getProperty() { return element; }
	U getProperty2() { return element2; }
	X getProperty3() { return element3; }

private:
	T element;
	U element2;
	X element3;
};
