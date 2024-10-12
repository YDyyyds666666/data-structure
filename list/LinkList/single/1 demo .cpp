#include "LinkList.h"
#include<iostream>
#include<string>
using namespace std;

int main1() {
	int a[] = { 1,2,3 };

	cout << sizeof(a) / sizeof(int) << endl;
	//当数组 a 在 C++ 中作为局部变量或全局变量定义时（如您所示），
	// 您可以使用 sizeof(a)/sizeof(int) 来计算数组 a 的元素个数。
	// 这是因为在这个上下文中，a 是一个具有明确大小和类型的数组，所以编译器知道 sizeof(a) 将返回整个数组的大小（以字节为单位），而 sizeof(int) 将返回一个整数的大小（也是以字节为单位）。
	// 将两者相除，您就可以得到数组中元素的数量。
	//然而，当数组作为函数参数传递时，情况就不同了。
	// 在函数参数列表中，数组名会退化为指向数组第一个元素的指针。
	// 这意味着，在函数内部，您无法再通过 sizeof 运算符来获取整个数组的大小，
	// 而只能获取指针的大小。因此，如果您想在函数中计算数组的大小，
	// 您必须显式地将数组的大小作为另一个参数传递给函数。
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