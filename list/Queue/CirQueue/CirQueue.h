#include<iostream>
const int QUEUESIZE = 100;
using namespace std;
template<class T>
class CirQueue {
private:
	T* data;
	int front;
	int rear;
	int mSize;
	//����Լ��frontָ���ͷԪ�ص�ǰһ��λ�ã�rearָ���βԪ��
	//ʵ�����鳤��=���г���+1
public:
	CirQueue() {
		front=rear = 0;
		mSize = QUEUESIZE+1;
		data = new T[mSize];
	};
	CirQueue(int size) {
		front = rear = 0;
		mSize = size+1;
		data = new T[mSize];
	};
	~CirQueue() {
		delete[] data;
	};
	bool enQueue(T item);
	bool deQueue(T* item);
	bool getFront(T& item);
	bool isEmpty() { return rear == front; };
	bool isFull() { return (rear + 1) % mSize == front; };
	int getLength() { return (rear - front + mSize) % mSize; };
	void clear();
	void display();
};
template<class T>
bool CirQueue<T>::enQueue(T x) {
	if (isFull())
		return false;
	rear = (rear + 1) % mSize;
	data[rear] = x;
	return true;
}
template<class T>
bool CirQueue<T>::deQueue(T* x) {
	if (isEmpty())
		return false;
	front = (front + 1) % mSize;
	*x=data[front];
	return true;
}
template<class T>
bool CirQueue<T>::getFront(T& x) {
	if (isEmpty())
		return false;
	int i = (front + 1) % mSize;
	x = data[i];
	return true;
}
template<class T>
void CirQueue<T>::clear() {
	front = rear = 0;
}

template<class T>
void CirQueue<T>::display() {
	if (isEmpty()) {
		cout << "Queue is empty." << endl;
		return;
	}

	int index = (front + 1) % mSize; // �ӵ�һ��Ԫ�ؿ�ʼ
	do {
		std::cout << data[index] << " ";
		index = (index + 1) % mSize;
	} while (index != rear);
	cout << endl;
}
