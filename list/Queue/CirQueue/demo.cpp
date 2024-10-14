#include<iostream>
#include "CirQueue.h"
using namespace std;

int main() {

	CirQueue<int> queue(4);
	queue.enQueue(6);
	int a=NULL;
	if(queue.getFront(a))
		cout << a << endl;

	while (!queue.isFull())
	{
		queue.enQueue(1);
	}
	cout << queue.getLength() << endl;
	while (!queue.isEmpty())
	{
		queue.deQueue(new int);
	}
	cout << queue.getLength() << endl;
}

