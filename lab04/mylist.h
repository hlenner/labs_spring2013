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
class MyList{

public:
	MyList();
	~MyList();
	void push_back(T x);
	int size() const;
	T at(int loc) const;
	
private:
	T *items;	
	int _size;
	int capacity;
};
#endif
template <typename T>
MyList<T>::MyList()
{
	_size=0;
	capacity=DEFAULT_LIST_SIZE;
	items= new T[capacity];
}
template <typename T>
MyList<T>:: ~MyList()
{
	delete [] items;
}
template <typename T>
void MyList<T>:: push_back(T x)
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
int MyList<T>:: size() const
{
	return _size;
}
template <typename T>
T MyList<T>:: at(int loc) const
{
	return items[loc];
}
