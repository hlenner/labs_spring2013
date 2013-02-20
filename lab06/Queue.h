#ifndef QUEUE_H
#define QUEUE_H
#include "llist.h"

template <typename T>
class Queue:private LList<T> {
	public:
	Queue();
	~Queue();
	int size() const;
	void push_back(const T& value);
	void pop_front();
	T& front();
	T& back();
	bool empty() const;
       
       private:
        
};
template<typename T>
Queue<T>:: Queue() 
{
LList<T>();
}
template<typename T>
Queue<T>:: ~Queue() 
{

}
template<typename T>
void Queue<T>:: push_back(const T &val)
{
	LList<T>::push_back(val);
}
template<typename T>
int Queue<T>:: size() const
{
	LList<T>::size();
}
template<typename T>
void Queue<T>:: pop_front()
{
	LList<T>::pop_front();
}
template<typename T>
T& Queue<T>:: front() 
{
	LList<T>::peek_front();
}
template<typename T>
T& Queue<T>:: back() 
{
	LList<T>::at(size()-1);
}
template<typename T>
bool Queue<T>:: empty() const
{
	LList<T>:: empty();
}

#endif

