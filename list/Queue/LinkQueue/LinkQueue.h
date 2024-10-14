#pragma once
#include<iostream>
template<class T>
struct Node
{
	T data;
	struct Node<T>* next;
};
template<class T>
class LinkQueue
{
public:
	LinkQueue()
	{
		front = rear = new Node<T>;
		front->next = NULL;
	}
	~LinkQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetFront();
	bool Empty() { return front == rear ? true : false; }
private:
	Node<T>* front;
	Node<T>* rear;
};
template<class T>
void LinkQueue<T>::EnQueue(T x)
{
	rear->next = new Node<T>;
	rear = rear->next;
	rear->data = x;
	rear->next = NULL;
}
template<class T>
T LinkQueue<T>::DeQueue()
{
	Node<T>* p = new Node<T>;
	p = front->next;                     //p出队
	if (!p)throw"Underflow";
	front->next = p->next;
	T x = p->data;
	delete p;
	if (!(front->next))rear = front;    //删除最后一个元素后
	return x;
}
template<class T>
T LinkQueue<T>::GetFront()
{
	if (!(front->next))throw"Overflow";
	return front->next->data;
}
template<class T>
LinkQueue<T>::~LinkQueue()
{
	while (front)
	{
		rear = front->next;
		delete front;
		front = rear;
	}
}