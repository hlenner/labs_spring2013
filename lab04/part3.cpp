#include "mylist.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class part3{

};

int main(int argc, char *argv[])
{
	cout << "here"<< endl;
	mylist<int> my_int_list;
	mylist<string> my_str_list;
	
	my_int_list.push_back(5);
	cout << my_int_list[0]<< endl;
	my_int_list.push_back(4);
	my_int_list.push_back(1);
	my_int_list.push_back(3);
	my_str_list.push_back("Haley");
	my_str_list.push_back("Kiki");
	my_str_list.push_back("Danielle");
	my_str_list.push_back("Hello");
	my_str_list.push_back("Sam");
	
	
	
	my_int_list[0]=3;
	cout << my_int_list[0]<< endl;
	
	
	/*for (int i=0; i<my_int_list.size(); i++){
		cout << my_int_list.at(i)<< endl;
	}
	for (int i=0; i<my_str_list.size(); i++){
		cout << my_str_list.at(i)<< endl;
	}*/
}
