#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node(T data = T(), Node<T>* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};
template<class T>
class Stack
{
public:
	Stack() { top = NULL; }
	Stack(Stack<T>* s);
	Stack(Stack<T>& s);
	~Stack();
	void Print();
	void Push(T x);
	T Pop();
	T GetTop();
	bool Empty() { return(NULL == top) ? true : false; }
private:
	Node<T>* top;
};
template<class T>
void Stack<T>::Print() {
	Node<T>* temp = top;
	while (temp) {
		cout << temp->data << " ";
		temp=temp->next;
	}
	cout << endl;
}

template<class T>
Stack<T>::Stack(Stack<T>* s) {
	if (s->Empty()) {
		top = NULL;
		return;
	}
	Node<T>* temp2 = s->top;
	Node<T>* temp1 = top =new Node<T>(temp2->data);        //添加new
	//注意new Node<T>(temp2->data);和Node<T>(temp2->data);的区别！！！
	while (temp2->next) {
		temp1->next = new Node<T>(temp2->next->data);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}

 // 复制构造函数
template<class T>
Stack<T>::Stack( Stack<T>& other) {
	if (other.Empty()) {
		top = nullptr;
		return;
	}

	Node<T>* temp2 = other.top;
	Node<T>* temp1 = top = new Node<T>(temp2->data);

	while (temp2->next) {
		temp1->next = new Node<T>(temp2->next->data);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}

template<class T>
void Stack<T>::Push(T x)
{
	Node<T>* p = new Node<T>(x, top);
	top = p;
}
template<class T>
T Stack<T>::Pop()
{
	if (Empty()) throw"下溢";
	T x = top->data;
	Node<T>* p = top;
	top = top->next;
	delete p;
	return x;
}
template<class T>
Stack<T>::~Stack()
{
	while (top)
	{
		Node<T>* p = top;
		top = top->next;
		delete p;
	}
}
template<class T>
T Stack<T>::GetTop()
{
	if (top)
		return top->data;
	else
		throw"error";
}






