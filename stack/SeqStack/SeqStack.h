
#pragma once
const int StackSize = 1024;
template<class T>
class SeqStack
{
public:
	SeqStack() {  top = -1; }   // top为-1时，栈为空
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
	if (top >= StackSize - 1)throw"上溢";
	top++;
	data[top] = x;
}

template<class T>
T SeqStack<T>::Pop()
{
	if (Empty())throw"下溢";
	top--;
	return data[top + 1];
}

template <class T>
T SeqStack<T>::GetTop()
{
	if (Empty())throw "下溢";
	return data[top];
};