#pragma once
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

