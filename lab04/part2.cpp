#include "mylist.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class part2{

};

int main(int argc, char *argv[])
{
	mylist<int> my_int_list;
	mylist<string> my_str_list;
	
	my_int_list.push_back(5);
	my_int_list.push_back(4);
	my_int_list.push_back(1);
	my_int_list.push_back(3);
	my_int_list.push_back(6);
	my_int_list.push_back(8);
	my_int_list.push_back(11);
	my_int_list.push_back(12);
	
	my_str_list.push_back("Haley");
	my_str_list.push_back("Kiki");
	my_str_list.push_back("Danielle");
	my_str_list.push_back("Hello");
	my_str_list.push_back("Eden");
	my_str_list.push_back("Eli");
	my_str_list.push_back("Rachel");
	my_str_list.push_back("Robert");
	my_str_list.push_back("Sam");
	
	my_str_list.remove("Sam");
	my_str_list.remove("Kiki");
	my_str_list.pop(2);
	my_str_list.pop(4);
	
	my_int_list.remove(4);
	my_int_list.remove(3);
	my_int_list.pop(0);
	my_int_list.pop(1);
	
	//these should be exceptions
	try{
		my_int_list.pop(11);
	}
	catch(int badValue){
		cerr << "Sorry you can't use value: " << badValue << endl;
	}
	try{
		my_int_list.at(21);
	}
	catch(int badValue){
		cerr << "Sorry you can't use value: " << badValue << endl;
	}
	try{
		my_str_list.pop(31);
	}
	catch(int badValue){
		cerr << "Sorry you can't use value: " << badValue << endl;
	}
	
	for (int i=0; i<my_int_list.size(); i++){
		cout << my_int_list.at(i)<< endl;
	}
	for (int i=0; i<my_str_list.size(); i++){
		cout << my_str_list.at(i)<< endl;
	}
}
