#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "FindPath.h"
#include "Print.h"
#include "MyClass.h"
#include "Stack.h"
using namespace std;

int main() {
	Stack<Box> MyStack;
	int arr[8][8] = { {1,1,1,1,1,1,1,1},
					  {1,0,1,1,0,1,0,1},
					  {1,0,0,1,0,0,0,1},
					  {1,1,0,0,1,0,0,1},
					  {1,0,0,1,1,1,0,1},
					  {1,0,1,0,0,0,1,1},
					  {1,0,0,0,1,0,0,1},
					  {1,1,1,1,1,1,1,1},
	};
	PrintMap(arr[0], 8, 8);
	cout << findPath(&arr[0][0], 8, 8, direct, MyStack) << endl;   //也可以传递arr[0]
	//记录的路径保存在MyStack中了
	cout << "拷贝构造函数测试：" << endl;
	Stack<Box> copy1(&MyStack);         //使用地址传递
	Stack<Box> copy2(MyStack);          //使用引用
	copy1.Print();
	copy2.Print();
	PrintWay(MyStack);
	//cout << MyStack.top->data << endl;
	PrintMap(arr[0], 8, 8 , MyStack);

	//拷贝构造函数可以访问类的其他实例的私有成员。这是因为拷贝构造函数是类的一个成员函数，
	// 当它被用来创建一个新的对象时，它是以被拷贝的对象为参数来调用的。
	// 在这个过程中，拷贝构造函数实际上是在“内部”使用被拷贝对象的数据成员，
	// 因此它需要能够访问这些成员，即使是私有的。
	//为了让拷贝构造函数能够访问私有成员，C++ 允许将拷贝构造函数声明为被拷贝对象所属类的友元函数。
	// 不过，在实际的编程实践中，通常不需要显式地这样做，因为拷贝构造函数本身就是类的一部分，它默认就有权限访问类的所有成员，包括私有成员。
}