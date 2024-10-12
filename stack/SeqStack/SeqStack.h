
#pragma once
const int StackSize = 1024;
template<class T>
class SeqStack
{
public:
	SeqStack() {  top = -1; }   // topΪ-1ʱ��ջΪ��
	void Push(T x);
	T Pop();
	T GetTop();
	bool Empty() { return top == -1 ? true : false; };
private:
	T data[StackSize];
	int top;
};
template<class T>
void SeqStack<T>::Push(T x)
{
	if (top >= StackSize - 1)throw"����";
	top++;
	data[top] = x;
}

template<class T>
T SeqStack<T>::Pop()
{
	if (Empty())throw"����";
	top--;
	return data[top + 1];
}

template <class T>
T SeqStack<T>::GetTop()
{
	if (Empty())throw "����";
	return data[top];
};