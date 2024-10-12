#pragma once
const int MAX_SIZE = 1024;
template<class T>
class SeqStack
{
public:
	SeqStack() { 
		size = MAX_SIZE;
		top = -1; 
		data = new T[size];
	}  
	SeqStack(int s) {  
		size = s;
		top = -1;
		data = new T[size];
	}   
	~SeqStack() {
		delete[] data;
	}
	void Push(T x);
	T Pop();
	T GetTop();
	bool isEmpty() { return top == -1 ? true : false; };
	bool isFull(){ return top == size -1 ? true : false; }
	void setFull() { top = -1; }
	class Full {};
	class Empty {};
private:
	T* data;
	int size;
	int top;
};
template<class T>
void SeqStack<T>::Push(T x)
{
	if (isFull()) throw Full();                         //throw"иорГ";
	data[++top] = x;
}
template<class T>
T SeqStack<T>::Pop()
{
	if (isEmpty()) throw Empty();                       //throw"обрГ";
	/*top--;
	return data[top + 1];*/
	return data[top--];
}
template <class T>
T SeqStack<T>::GetTop()
{
	if (isEmpty())  throw Empty();                                  //throw "обрГ";
	return data[top];
};