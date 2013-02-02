#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

const int DEFAULT_LIST_SIZE=10;

using namespace std;

class List{

public:
	List();
	~List();
	void push_back(string x);
	int size() const;
	string at(int loc) const;
	bool operator==(const List &lst);
	
	
private:
	string *items;	
	int _size;
	int capacity;
};

List::List()
{
	_size=0;
	capacity=DEFAULT_LIST_SIZE;
	items= new string[capacity];
}
List:: ~List()
{
	delete [] items;
}
bool List:: operator==(const List &lst)
{
	
}
void List:: push_back(string x)
{
	if (_size<capacity){
		items[_size++] = x;
		}
	else{
		capacity=capacity*2;
		string* moreitems= new string[capacity];
		for (int i = 0; i<_size; i++){
			moreitems[i]=items[i];
			}
			moreitems[_size] = x;
			_size++;
			delete[] items;
	}
}
int List:: size() const
{
	return _size;
}
string List:: at(int loc) const
{
	return items[loc];
}
