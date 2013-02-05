#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

const int DEFAULT_LIST_SIZE=10;

using namespace std;

template <typename T>
class mylist{

public:
	mylist();
	~mylist();
	void push_back(T x);
	int size() const;
	T& at(int loc) const;
	bool remove(T val);
	T pop(int loc);
	T operator[](int rhs);
	//T& operator[](int lhs);
	
	
private:
	T *items;	
	int _size;
	int capacity;
};
#endif
template <typename T>
mylist<T>::mylist()
{
	_size=0;
	capacity=DEFAULT_LIST_SIZE;
	items= new T[capacity];
	
	
}
template <typename T>
mylist<T>::~mylist()
{
	delete [] items;
}
template <typename T>
void mylist<T>::push_back(T x)
{
	if (_size<capacity){
		items[_size++] = x;
		}
	else{
		capacity=capacity*2;
		T* moreitems= new T[capacity];
		for (int i = 0; i<_size; i++){
			moreitems[i]=items[i];
			}
			moreitems[_size] = x;
			_size++;
			delete []items;
	}
}
template <typename T>
int mylist<T>:: size() const
{
	return _size;
}
template <typename T>
T& mylist<T>:: at(int loc) const
{
if (loc > _size){
	throw loc;
	}
else{
	return items[loc];
	}
}
template <typename T>
bool mylist<T>::remove(T val)
{
	for(int i=0; i<_size; i++)
	{
		if (items[i]==val)
		{
			for(int j=i; j <_size;j++)
			{
				items[j]=items[j+1];
				}
				_size--;
				return true;
		}
	}
	return false;
}
template <typename T>
T mylist<T>::pop(int loc)
{
	if (loc > _size)
	{
		throw loc;
	}
	else{
	T value;
	value = items[loc];
	for (int i=loc; i<_size ; i++){
				items[i]=items[i+1];
				}
		_size--;
	return value;
	}
}
template <typename T>
T mylist<T>::operator[](int rhs)
{
	return items[rhs];
}
