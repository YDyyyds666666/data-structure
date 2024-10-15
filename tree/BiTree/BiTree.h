#pragma once
#include<iostream>
#include<vector>
#include "Queue.h"
#include "BiNode.h"
#include "Stack.h"
using namespace std;
struct element {
	BiNode* node;
	int flag;
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
	void preOrder() { preOrder(root); cout << endl; };
	void inOrder() { inOrder(root); cout << endl;};
	void postOrder() { postOrder(root); cout << endl;};
	void leverOrder();


private:
	BiNode* create(BiNode* bt);
	BiNode* create(vector<char>& arr, int index);
	//void create(BiNode* & bt);
	void release(BiNode* bt);
	void preOrder(BiNode* bt);
	void inOrder(BiNode* bt);
	void postOrder(BiNode* bt);
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

void BiTree::preOrder(BiNode* bt) {
	if (bt == NULL) {
		return;
	}
	else {
		cout << bt->data << " ";
		preOrder(bt->lchild);
		preOrder(bt->rchild);
	}
}

void BiTree::inOrder(BiNode* bt) {
	if (bt == NULL) {
		return;
	}
	else {
		inOrder(bt->lchild);
		cout<<bt->data<<" ";
		inOrder(bt->rchild);
	}
}


void BiTree::postOrder(BiNode* bt) {
	if (bt == NULL) {
		return;
	}
	else {
		postOrder(bt->lchild);
		postOrder(bt->rchild);
		cout << bt->data << " ";
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
	cin>>data;
	if (data == '#')
		bt = NULL;
	else {
		bt = new BiNode;
		bt->data = data;
		bt->lchild=create(bt->lchild);
		bt->rchild=create(bt->rchild);
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




//template<class T>
//void BiTree<T>::create(BiNode<T>* & bt) {
//	input(ch);
//	if (ch == '#')
//		bt = NULL;
//	else {
//		bt = new BiNode<T>;
//		bt->data = ch;
//		create(bt->lchild);
//		create(bt->rchild);
//	}
//	return;
//}

