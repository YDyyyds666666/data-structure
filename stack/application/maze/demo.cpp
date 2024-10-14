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
	cout << findPath(&arr[0][0], 8, 8, direct, MyStack) << endl;   //Ҳ���Դ���arr[0]
	//��¼��·��������MyStack����
	cout << "�������캯�����ԣ�" << endl;
	Stack<Box> copy1(&MyStack);         //ʹ�õ�ַ����
	Stack<Box> copy2(MyStack);          //ʹ������
	copy1.Print();
	copy2.Print();
	PrintWay(MyStack);
	//cout << MyStack.top->data << endl;
	PrintMap(arr[0], 8, 8 , MyStack);

	//�������캯�����Է����������ʵ����˽�г�Ա��������Ϊ�������캯�������һ����Ա������
	// ��������������һ���µĶ���ʱ�������Ա������Ķ���Ϊ���������õġ�
	// ����������У��������캯��ʵ�������ڡ��ڲ���ʹ�ñ�������������ݳ�Ա��
	// �������Ҫ�ܹ�������Щ��Ա����ʹ��˽�еġ�
	//Ϊ���ÿ������캯���ܹ�����˽�г�Ա��C++ �����������캯������Ϊ�������������������Ԫ������
	// ��������ʵ�ʵı��ʵ���У�ͨ������Ҫ��ʽ������������Ϊ�������캯������������һ���֣���Ĭ�Ͼ���Ȩ�޷���������г�Ա������˽�г�Ա��
}