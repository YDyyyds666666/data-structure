#include "CircularLinkList.h"
#include<iostream>
#include<string>
using namespace std;

int main1() {
	int a[] = { 1,2,3 };

	CircularLinkList<int> list1 = CircularLinkList<int>(a, 3);
	CircularLinkList<int> list2 = CircularLinkList<int>();
	list2.PrintList();
	list1.PrintList();
	list1.Reverse();
	list1.PrintList();


	cout << list1.GetLength() << "  " << list2.GetLength() << endl;
	cout << list1.Get(3)->data << endl;
	cout << "通过最后一个节点查找第一个元素：" << endl;
	cout << list1.Get(list1.GetLength())->next->next->data << endl;
	list1.Get(-1);
	list1.Get(4);

	if (list1.Locate(4)) {
		cout << list2.Locate(4) << endl;
	}
	else {
		cout << "查找失败" << endl;
	};
	list1.Delete(1);
	list1.PrintList();
	cout << list1.rear->data << endl;
	cout << list1.rear->next->next->data << endl;
	list1.Reverse();
	list1.PrintList();
	list1.Insert(4, 88);
	list1.PrintList();
	list1.Delete(4);
	list1.Delete(1);
	list1.PrintList();
	return 0;
}