#include "LinkList.h"
#include<iostream>
#include<string>
using namespace std;

int main1() {
	int a[] = { 1,2,3 };

	cout << sizeof(a) / sizeof(int) << endl;
	//������ a �� C++ ����Ϊ�ֲ�������ȫ�ֱ�������ʱ��������ʾ����
	// ������ʹ�� sizeof(a)/sizeof(int) ���������� a ��Ԫ�ظ�����
	// ������Ϊ������������У�a ��һ��������ȷ��С�����͵����飬���Ա�����֪�� sizeof(a) ��������������Ĵ�С�����ֽ�Ϊ��λ������ sizeof(int) ������һ�������Ĵ�С��Ҳ�����ֽ�Ϊ��λ����
	// ��������������Ϳ��Եõ�������Ԫ�ص�������
	//Ȼ������������Ϊ������������ʱ������Ͳ�ͬ�ˡ�
	// �ں��������б��У����������˻�Ϊָ�������һ��Ԫ�ص�ָ�롣
	// ����ζ�ţ��ں����ڲ������޷���ͨ�� sizeof ���������ȡ��������Ĵ�С��
	// ��ֻ�ܻ�ȡָ��Ĵ�С����ˣ���������ں����м�������Ĵ�С��
	// ��������ʽ�ؽ�����Ĵ�С��Ϊ��һ���������ݸ�������
	LinkList<int> list1 = LinkList<int>(a, 3);
	LinkList<int> list2 = LinkList<int>();
	cout << list2.GetLength() << endl;
	list2.PrintList();
	list1.PrintList();
    list1.Reverse();
	list1.PrintList();
	list1.Insert(4, 88);
	list1.PrintList();
	list1.Delete(4);
	list1.Delete(1);
	list1.PrintList();
	return 0;
}