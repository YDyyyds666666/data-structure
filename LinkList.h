#pragma once
#include<iostream>
#include "Node.h"
using namespace std;
template<class T>
class LinkList
{
public:
	LinkList() { front = new Node<T>; front->next = NULL; };
	LinkList(T a[],int n);
	
	//���������뺯��ʵ��ֻ����һ����Ĭ�ϲ�����
	~LinkList();
	void PrintList();
	int GetLength();
	Node<T>* Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);
	void Reverse();
private:
	Node<T>* front=NULL;
};

template<class T>
LinkList<T>::LinkList(T a[],  int n) {
	//ͷ�巨
	/*front = new Node<T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; i--) {
		Node<T>* temp = new Node<T>(a[i],front->next);
		front->next = s;
	}*/
	//β�巨
	front = new Node<T>();  //������
	front->next = nullptr;
	Node<T>* rear = front;
	for (int i = 0; i < n; i++) {
		rear->next = new Node<T>(a[i]);
		rear = rear->next;
	}
}
template<class T>
LinkList<T>::~LinkList() {
	Node<T>* temp = front;
	Node<T>* next;
	while (temp) {
		next = temp->next;
		delete temp;
		temp = next;
	}
}
template<class T>
void LinkList<T>::PrintList() {
	Node<T>* temp = front->next;
	if (!temp) {
		cout << "����Ϊ��" << endl;
		return;
	}
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
template<class T>
int LinkList<T>::GetLength() {
	Node<T>* temp = front->next;
	int count=0;
	while (temp) {
		count++;
		temp = temp->next;
	}
	return count;
}
template<class T>
Node<T>* LinkList<T>::Get(int i) {
	Node<T>* temp = front;
	if (i <0) {
		cout << "λ�ò��Ϸ�" << endl;
		return NULL;
	}           
	//�涨����0ʱ ����ͷ���
	if (i == 0) { return front; }
	for (int j = 0; j < i; j++) {
		if (temp->next) { temp = temp->next; }
		else { 
			cout << "λ�ó�����Χ" << endl;
			return NULL; 
		};
	}
	return temp;
}

template<class T>
int LinkList<T>::Locate(T x) {
	Node<T>* temp = front->next;
	if (!temp) {
		cout << "������" << endl;
		return -1;
	}
	int i = 0;              //�涨������1��ʼ
	while (temp) {
		i++;
		if (temp->data == x) {
			return i;
		}
		temp = temp->next;
	}
	cout << "δ�ҵ�Ԫ��" << endl;
	return -1;
};
template<class T>
void LinkList<T>::Insert(int i, T x) {
	//λ�ô�1��ʼ ���ǹ涨���Բ��뵽���һ��Ԫ�ص�λ�õĺ���
	Node<T>* node = Get(i-1);
	if (!node) {
		cout << "����λ�ò��Ϸ�" << endl;
		return;
	}
	Node<T>* temp = new Node<T>(x, node->next);
	node->next = temp;
}

template<class T>
T LinkList<T>::Delete(int i){
	if (i <= 0) {
		cout << "ɾ��λ�ô���" << endl;
		return NULL;
	} 
	Node<T>* temp1 = Get(i-1);
	Node<T>* temp2 = Get(i);
	if (!temp2 ) {
		cout << "ɾ��λ�ó�����Χ" << endl;
		return NULL;
	}
	temp1->next = temp2->next;
	T x = temp2->data;
	delete temp2;
	return x;
}

//template<class T>
//void LinkList<T>::Reverse() {
//	Node<T>* p = front->next;
//	Node<T>* q;
//	front->next = NULL;
//	q = front->next;        // q = new Node<T>(p->data) �޷�Ϊ������ӽ��
//	Node<T>* temp;
//	while (p) {
//		q = new Node<T>(p->data);
//		temp = p->next;
//		delete p;
//		p = temp;
//	}
//}

template<class T>
void LinkList<T>::Reverse() {
	Node<T>* p = front->next;
	Node<T>* temp;
	front->next = NULL;
	while (p) {
		temp = new Node<T>(p->data, front->next);
		front->next = temp;
		temp = p->next;
		delete p;
		p = temp;
	}
}


