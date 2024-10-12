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
	//尾插法
	rear = front = new Node<T>();    //加括号
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
		cout << "链表为空" << endl;
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
			cout << "位置不能为负数" << endl;
			return NULL;
		}
		printf("第%d个元素不存在\n", i);
		return NULL;
	}
	//规定等于0时 返回头结点
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
		cout << "空链表" << endl;
		return 0;
	}
	int i = 0;              //规定索引从1开始
	while (temp!=front) {
		i++;
		if (temp->data == x) {
			return i;
		}
		temp = temp->next;
	}
	cout << "未找到元素" << endl;
	return 0;
};



template<class T>
void CircularLinkList<T>::Insert(int i, T x) {
	//位置从1开始 我们规定可以插入到最后一个元素的位置的后面
	Node<T>* node = Get(i - 1);
	if (!node) {
		cout << "输入位置不合法" << endl;
		return;
	}
	Node<T>* temp = new Node<T>(x, node->next);
	node->next = temp;
}
template<class T>
T CircularLinkList<T>::Delete(int i) {
	if (i <= 0) {
		cout << "删除位置不能为负数" << endl;
		return NULL;
	}
	if (i > GetLength()) {
		cout << "删除位置超出范围" << endl;
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
//		// 空链表或只有一个节点
//		return;
//	}
//	Node<T>* current = front->next;
//	Node<T>* prev = front;
//	Node<T>* next = nullptr;
//	while (current != front) {
//		// 保存下一个节点
//		next = current->next;
//		// 反转当前节点的指针
//		current->next = prev;
//		// 移动 prev 和 current 指针
//		prev = current;
//		current = next;
//	}
//	// 将最后一个节点的 next 指向前一个节点
//	current->next = prev;
//	// 更新 front 和 rear 指针
//	rear = front->next;
//	front->next = prev;
//}

// 反转链表
void  CircularLinkList<T>::Reverse() {
	if (front == rear) {
		// 空链表或只有一个节点
		return;
	}

	Node<T>* current = front->next; // 当前节点
	Node<T>* toBeRear = current;
	Node<T>* pre = front;           // 上一个节点
	Node<T>* next = nullptr;        // 下一个节点
	
	while (current != front) {
		// 保存下一个节点
		next = current->next;
		// 反转当前节点的指针
		current->next = pre;
		// 移动 prev 和 current 指针
		pre = current;
		current = next;
	}
	// 最后修改头结点的next域即可
	current->next = pre;
	// 更新 rear 指针即可
	rear = toBeRear;
}
