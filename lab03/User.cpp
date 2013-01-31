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
void List:: push_back(string x)
{
	if (_size<capacity){
		items[_size++] = x;
		cout << "hi" << endl;
		}
	else{
		capacity=capacity*2;
		string* moreitems= new string[capacity];
		for (int i = 0; i<_size; i++){
			moreitems[i]=items[i];
			}
			moreitems[_size] = x;
			_size++;
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

class User{

public:
	User();
	User(string name, int age);
	User(int i);
	~User();
	void setAge(int age);
	void setName(string name);
	int getAge();
	string getName();
	void addFriend(string s);

private:
	string _name;
	int _age;
	List friends;
};

int main(int argc, char *argv[])
{
		vector<User*> userList;
		int age;
		string name;
		cout << "Enter first name, space, then age of each person. When finished, type done where you would type the next name." << endl;
		do {
			cin >> name >> age;
			if (name!="done"){
			User* i= new User(name, age);
			userList.push_back(i);
			}
		}
		while(name!="done");
		
		cout << "Enter two names separated by a space, the first being a User and the second being the friend of the User that you want to add. When finished, type done where you would type the next name." << endl;
		string user, newFriend;
		while (user != "done"){
			cin >> user >> newFriend;
		for (int i=0; i<userList.size(); i++){
			if (user == (*userList.at(i)).getName()){
				(*userList[i]).addFriend(newFriend);

				}
			}
		}
}
User::User()
{
	List *friends = new List();
}
User::User(int i)
{
	
}
User::User(string name, int age)
{
	_name = name;
	_age = age;
}
User::~User()
{

}
string User:: getName()
{
	return _name;
}
int User:: getAge()
{
	return _age;
}
void User:: setName(string name)
{
	_name=name;
}
void User:: setAge(int age)
{
	_age=age;
}
void User:: addFriend(string s)
{
	friends.push_back(s);
}
