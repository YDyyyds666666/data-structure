#include "LinkQueue.h"
#include<cstring>
#include<iostream>
using namespace std;
class PHONEBOOK {
private:
	int m_ID;
	string m_name;
	string m_phone;
	string m_group;
public:
	PHONEBOOK()
	{
		m_ID = 0;
		m_name = "?";
		m_phone = "0";
		m_group = "?";
	};
	PHONEBOOK(int ID, const char* name, const char* phone, char const* group) {
		m_ID = ID;
		m_name = name;
		m_phone = phone;
		m_group = group;
	};
	void print() {
		cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
	};
	bool operator== (PHONEBOOK& p) {
		if (p.m_ID == m_ID)
			return true;
		return false;
	};
};
int main()
{
	PHONEBOOK r1(20181209, "phoenix", "15930209020", "teacher");
	PHONEBOOK r2(20181127, "Tom", "13934621123", "family");
	PHONEBOOK r3(20181156, "John", "1324579880", "classmates");
	PHONEBOOK r4(20181133, "Lisa", "1378001822", "classmates");
	LinkQueue <PHONEBOOK> MyQueue;
	MyQueue.EnQueue(r1);
	MyQueue.EnQueue(r2);
	MyQueue.EnQueue(r3);
	MyQueue.EnQueue(r4);
	MyQueue.DeQueue();
	MyQueue.GetFront().print();
}