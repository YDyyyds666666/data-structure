#pragma once
#include<iostream>
#include "Node.h"
using namespace std;
template<class T>
class CircularLinkList
{
public:
	CircularLinkList() { front = new Node<T>(); rear = front; rear->next = front; };
	CircularLinkList(T a[], int n);
	~CircularLinkList();
	void PrintList();
	int GetLength();
	Node<T>* Get(int i);
	int Locate(T x);
	void Insert(int i, T x);
	T Delete(int i);
	void Reverse();
//private:
	Node<T>* front = NULL;
	Node<T>* rear = NULL;
};

template<class T>
CircularLinkList<T>::CircularLinkList(T a[], int n) {
	//β�巨
	rear = front = new Node<T>();    //������
	rear->next = front;
	Node<T>* temp;
	for (int i = 0; i < n; i++) {
		temp = new Node<T>(a[i],rear->next);
		rear->next = temp;
		rear = rear->next;
	}
}
template<class T>
CircularLinkList<T>::~CircularLinkList() {
	rear->next = NULL;
	Node<T>* temp = front;
	Node<T>* next;
	while (temp) {
		next = temp->next;
		delete temp;
		temp = next;
	}
}

template<class T>
void CircularLinkList<T>::PrintList() {
	Node<T>* temp = front->next;
	if (temp == front) {
		cout << "����Ϊ��" << endl;
		return;
	}
	while (temp !=front ) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
template<class T>
int CircularLinkList<T>::GetLength() {
	Node<T>* temp = front->next;
	int count = 0;
	while (temp!=front) {
		count++;
		temp = temp->next;
	}
	return count;
}
template<class T>
Node<T>* CircularLinkList<T>::Get(int i) {
	Node<T>* temp = front;
	if (i < 0 || i> GetLength() ) {
		if (i < 0) {
			cout << "λ�ò���Ϊ����" << endl;
			return NULL;
		}
		printf("��%d��Ԫ�ز�����\n", i);
		return NULL;
	}
	//�涨����0ʱ ����ͷ���
	if (i == 0) { return front; }

	for (int j = 0; j < i; j++) {
		temp = temp->next; 
	}
	return temp;
}
template<class T>
int CircularLinkList<T>::Locate(T x) {
	Node<T>* temp = front->next;
	if (temp == front) {
		cout << "������" << endl;
		return 0;
	}
	int i = 0;              //�涨������1��ʼ
	while (temp!=front) {
		i++;
		if (temp->data == x) {
			return i;
		}
		temp = temp->next;
	}
	cout << "δ�ҵ�Ԫ��" << endl;
	return 0;
};



template<class T>
void CircularLinkList<T>::Insert(int i, T x) {
	//λ�ô�1��ʼ ���ǹ涨���Բ��뵽���һ��Ԫ�ص�λ�õĺ���
	Node<T>* node = Get(i - 1);
	if (!node) {
		cout << "����λ�ò��Ϸ�" << endl;
		return;
	}
	Node<T>* temp = new Node<T>(x, node->next);
	node->next = temp;
}
template<class T>
T CircularLinkList<T>::Delete(int i) {
	if (i <= 0) {
		cout << "ɾ��λ�ò���Ϊ����" << endl;
		return NULL;
	}
	if (i > GetLength()) {
		cout << "ɾ��λ�ó�����Χ" << endl;
		return NULL;
	}
	if (i == GetLength()) {
		rear = Get(i - 1);
	}
	Node<T>* temp1 = Get(i - 1);
	Node<T>* temp2 = Get(i);
	temp1->next = temp2->next;
	T x = temp2->data;
	delete temp2;
	return x;
}


template<class T>
//void CircularLinkList<T>::Reverse() {
//	if (front == rear) {
//		// �������ֻ��һ���ڵ�
//		return;
//	}
//	Node<T>* current = front->next;
//	Node<T>* prev = front;
//	Node<T>* next = nullptr;
//	while (current != front) {
//		// ������һ���ڵ�
//		next = current->next;
//		// ��ת��ǰ�ڵ��ָ��
//		current->next = prev;
//		// �ƶ� prev �� current ָ��
//		prev = current;
//		current = next;
//	}
//	// �����һ���ڵ�� next ָ��ǰһ���ڵ�
//	current->next = prev;
//	// ���� front �� rear ָ��
//	rear = front->next;
//	front->next = prev;
//}

// ��ת����
void  CircularLinkList<T>::Reverse() {
	if (front == rear) {
		// �������ֻ��һ���ڵ�
		return;
	}

	Node<T>* current = front->next; // ��ǰ�ڵ�
	Node<T>* toBeRear = current;
	Node<T>* pre = front;           // ��һ���ڵ�
	Node<T>* next = nullptr;        // ��һ���ڵ�
	
	while (current != front) {
		// ������һ���ڵ�
		next = current->next;
		// ��ת��ǰ�ڵ��ָ��
		current->next = pre;
		// �ƶ� prev �� current ָ��
		pre = current;
		current = next;
	}
	// ����޸�ͷ����next�򼴿�
	current->next = pre;
	// ���� rear ָ�뼴��
	rear = toBeRear;
}
