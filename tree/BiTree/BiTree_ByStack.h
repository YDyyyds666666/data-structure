#pragma once
#include<iostream>
#include<vector>
#include "Queue.h"
#include "Stack.h"
using namespace std;
class BiNode {
public:
	char data;
	BiNode* lchild, * rchild;
	BiNode(){
	}
	BiNode(char data, BiNode* lchild=nullptr ,BiNode* rchild=nullptr) {
		this->data = data; 
		this->lchild = lchild;
		this->rchild = rchild;
	}
};
class element {
public:
	BiNode* node;
	int flag;
	element(){}
	element(BiNode* node, int flag) {
		this->node = node;
		this->flag = flag;
	}
};
class BiTree {
private:
	BiNode* root;
public:
	BiTree() {
		cout << "以前序遍历顺序输入字符，空节点使用#" << endl;
		root = create(root);
	}
	BiTree(vector<char>& arr) {
		root = create(arr, 0);
	}
	~BiTree() { release(root); }
	void leverOrder();
	void preOrder();
	void inOrder();
	void postOrder();

private:
	BiNode* create(BiNode* bt);
	BiNode* create(vector<char>& arr, int index);
	void release(BiNode* bt);
};

void BiTree::release(BiNode* bt) {
	if (bt == nullptr) {
		return;
	}
	else {
		release(bt->lchild);
		release(bt->rchild);
		delete bt;
	}
}

void BiTree::leverOrder() {
	if (root == NULL)
		return;
	LinkQueue<BiNode*> queue;
	BiNode* q;
	queue.enQueue(root);
	while (!queue.isEmpty()) {
		q = queue.deQueue();
		cout << q->data << " ";
		if (q->lchild != NULL)
			queue.enQueue(q->lchild);
		if (q->rchild != NULL)
			queue.enQueue(q->rchild);
	}
}

BiNode* BiTree::create(BiNode* bt) {
	char data;
	cin >> data;
	if (data == '#')
		bt = NULL;
	else {
		bt = new BiNode;
		bt->data = data;
		bt->lchild = create(bt->lchild);
		bt->rchild = create(bt->rchild);
	}
	return bt;
}

BiNode* BiTree::create(vector<char>& arr, int index) {
	if (index >= arr.size() || arr[index] == '#') {
		return nullptr;
	}
	BiNode* newNode = new BiNode(arr[index]);
	newNode->lchild = create(arr, 2 * index + 1);
	newNode->rchild = create(arr, 2 * index + 2);
	return newNode;
}

void BiTree::preOrder() {
	LinkStack<BiNode*> s;
	BiNode* p = root;
	while (p != NULL || !s.Empty()) {
		while (p != NULL) {
			cout << p->data << " ";
			s.Push(p);
			p = p->lchild;
		}if (!s.Empty()) {
			p = s.Pop();
			p = p->rchild;
		}
	}
	cout << endl;
};

void BiTree::inOrder() {
	LinkStack<BiNode*> s;
	BiNode* p = root;
	while (p != NULL || !s.Empty()) {
		while (p != NULL) {
			s.Push(p);
			p = p->lchild;
		}if (!s.Empty()) {
			p = s.Pop();
			cout << p->data << " ";
			p = p->rchild;
		}
	}
	cout << endl;
};

void BiTree::postOrder() {
	LinkStack<element> s;
	BiNode* p = root;
	while (p != NULL || !s.Empty()) {
		if (p != NULL) {
			element elem(p,1);
			s.Push(elem);           //第一次入栈
			p = p->lchild;
		}
		else {
			element elem = s.Pop();
			p = elem.node;
			if (elem.flag == 1) {
				elem.flag = 2;
				s.Push(elem);
				p = p->rchild;
			}
			else {
				cout << p->data << " ";
				p = NULL;
			}
		}
	}
	cout << endl;
};





