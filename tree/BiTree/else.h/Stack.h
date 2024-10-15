#pragma once
#include<iostream>
using namespace std;
template<class T>
class SNode
{
public:
	T data;
	SNode<T>* next;
	SNode(T data = T(), SNode<T>* next = nullptr) {
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
	struct SNode<T>* top;
};
template<class T>
void LinkStack<T>::Push(T x)
{
	SNode<T>* p = new SNode<T>(x, top);
	top = p;
}
template<class T>
T LinkStack<T>::Pop()
{
	if (Empty()) throw"ÏÂÒç";
	T x = top->data;
	SNode<T>* p = top;
	top = top->next;
	delete p;
	return x;
}
template<class T>
LinkStack<T>::~LinkStack()
{
	while (top)
	{
		SNode<T>* p = top;
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




