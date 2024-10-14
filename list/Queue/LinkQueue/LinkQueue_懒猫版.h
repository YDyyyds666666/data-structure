#pragma once
#include<iostream>
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node() {
	}
	Node(T data=T(), Node<T>* next=nullptr) {
		this->data = data;
		this->next = next;
	}
};
template<class T>
class LinkQueue
{
public:
	LinkQueue()
	{
		front = rear = new Node<T>();
		length = 0;
	}
	~LinkQueue();
	void enQueue(T x);
	bool deQueue(T &item);
	bool getFront(T& item);
	bool isEmpty() { return front == rear ? true : false; }
	void clear();
	void display();
	int GetLength() { return length; };
private:
	Node<T>* front;
	Node<T>* rear;
	int length;
};
template<class T>
void LinkQueue<T>::enQueue(T x)
{
	rear->next = new Node<T>(x);
	rear = rear->next;
	length++;
}
template<class T>
bool LinkQueue<T>::deQueue(T& item)
{
	if (isEmpty()) {
		return false;
	}
	Node<T>* p = front->next;                       //p出队
	item = p->data;
	front->next = p->next;
	delete p;
	if (!(front->next))rear = front;              //如果删除最后一个元素
	length--;
	return true;
}
template<class T>
bool LinkQueue<T>::getFront(T& item)
{
	if (isEmpty()) return false;
	item= front->next->data;
	return true
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
template<class T>
void LinkQueue<T>::clear()
{
	while (front)
	{
		rear = front->next;
		delete front;
		front = rear;
	}
	rear = front;
	length = 0;
}
template<class T>
void LinkQueue<T>::display()
{
	Node<T>* current = front->next;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

