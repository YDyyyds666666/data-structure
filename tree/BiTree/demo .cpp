#include<iostream>
#include "BiTree_ByStack.h"
using namespace std;
int main() {
	// a b # f # # c d # # d # #
	/*BiTree tree1;
	tree1.preOrder();
	tree1.inOrder();
	tree1.postOrder();*/
	vector<char> vector= { 'a', '#', 'c' };
	BiTree tree2(vector);
	tree2.preOrder();
	tree2.inOrder();
	tree2.postOrder();
	return 0;
}