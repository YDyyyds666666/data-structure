#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node(T data=T(), Node<T>* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};
template<class T>
class LinkStack
{
public:
	LinkStack() { top = NULL; }
	~LinkStack();
	void Push(T x);
	T Pop();
	T GetTop();
	bool Empty() { return(NULL == top) ? true : false; }
private:
	struct Node<T>* top;
};
template<class T>
void LinkStack<T>::Push(T x)
{
	Node<T>* p = new Node<T>(x,top);
	top = p;
}
template<class T>
T LinkStack<T>::Pop()
{
	if (Empty()) throw"ÏÂÒç";
	T x = top->data;
	Node<T>* p = top;
	top = top->next;         
	delete p;               
	return x;
}
template<class T>
LinkStack<T>::~LinkStack()
{
	while (top)
	{
		Node<T>* p = top;
		top = top->next;
		delete p;
	}
}
template<class T>
T LinkStack<T>::GetTop()
{
	if (top)
		return top->data;
	else
		throw"error";
}




