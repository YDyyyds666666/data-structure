#pragma once
#include<iostream>
template<class T>
struct QNode
{
	T data;
	struct QNode<T>* next;
};
template<class T>
class LinkQueue
{
public:
	LinkQueue()
	{
		front = rear = new QNode<T>;
		front->next = NULL;
	}
	~LinkQueue();
	void enQueue(T x);
	T deQueue();
	T GetFront();
	bool isEmpty() { return front == rear ? true : false; }
private:
	QNode<T>* front;
	QNode<T>* rear;
};
template<class T>
void LinkQueue<T>::enQueue(T x)
{
	rear->next = new QNode<T>;
	rear = rear->next;
	rear->data = x;
	rear->next = NULL;
}
template<class T>
T LinkQueue<T>::deQueue()
{
	QNode<T>* p = new QNode<T>;
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
