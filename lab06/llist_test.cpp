#include <iostream>
#include "llist.h"
#include "Queue.h"
#include "Stack.h"

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

  cout << endl;
  cout<< "Testing Queue" << endl;
  
  Queue<int> myq;
  myq.push_back(5);
  myq.push_back(6);
  myq.push_back(7);
  myq.push_back(8);
  cout << "Front item is: " << myq.front() << endl;
  cout << "Back item is: " << myq.back() << endl;
  cout << "Size: " << myq.size() << endl;
  myq.pop_front();
  cout << "Popped first value, new first value is: " << myq.front() << endl;
  cout << "New size: " << myq.size() << endl;
  for (int i=0; i<myq.size(); i++){
  	cout << myq.at(i) << " "  ;
  }
  cout << endl;
  cout << endl;
  cout << "Testing Stack" << endl;
  Stack<int> myStack;
  
  myStack.push(5); 
  myStack.push(6);
  myStack.push(7);
  myStack.push(8);
  myStack.pop();
  cout << "Top value is: " << myStack.top() << endl;
  for (int i=0; i<myStack.size(); i++){
  	cout << myStack.at(i) << " "  ;
  }
  
  return 0;
}