#include <iostream>
#include "llist.h"
#include "Queue.h"

using namespace std;

int main()
{
cout << "Testing Linked List" << endl;
  LList<int> mylist;
  mylist.push_back(5);
  mylist.push_back(6);
  mylist.push_back(7);
  cout << "Front item is: " << mylist.peek_front() << endl;
  cout << "Item at location 1 is " << mylist.at(1) << endl;
   cout << "Item at location 2 is " << mylist.at(2) << endl;
  mylist.remove(6);
  //mylist.insert(0,4);
  //mylist.insert(3,8);
  cout << "List contents (and removal)" << endl;
  cout << "Size: " << mylist.size() << endl;
  while(!mylist.empty()){
    cout << mylist.peek_front() << endl;
    mylist.pop_front();
  }
  cout << "End testing linkedlist" << endl;
  cout << endl;
  
  
  
  return 0;
}
