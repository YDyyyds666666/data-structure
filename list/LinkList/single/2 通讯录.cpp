#include "LinkList.h"
#include<cstring>
#include<iostream>
using namespace std;
class PHONEBOOK {
public:
	int m_ID;
	string m_name;
	string m_phone;
	string m_group;
public:
	PHONEBOOK() {};
	PHONEBOOK(int ID, const char* name, const char* phone, char const* group) {
		m_ID = ID;
		m_name = name;
		m_phone = phone;
		m_group = group;
	};
	/*void print() {
		cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
	};*/
	bool operator== (PHONEBOOK& p) {
		if (p.m_ID == m_ID)
			return true;
		return false;
	};
};
//��Ҫ���ж����������������
ostream& operator<<(ostream& cout, PHONEBOOK& p) {
	cout << p.m_ID << '\t' << p.m_name << '\t' << p.m_phone << '\t' << p.m_group << endl;
	return cout;
}
int main() {
	PHONEBOOK pbook[4] = { {20181208, "Mary", "13011221827", "classmates" },
		{20181127, "Tom", "13934621123", "family"},
		{20181156, "John", "1324579880", "classmates" },
		{20181133, "Lisa", "1378001822", "classmates"}
	};
	PHONEBOOK record(20181209, "phoenix", "15930209020", "teacher");
	LinkList <PHONEBOOK> list(pbook, 4);
	cout << "ͨ��¼�����б�" << endl;
	list.PrintList();
	list.Insert(1, record);
	cout << "ͨ��¼�����б�" << endl;
	list.PrintList();
	cout << "�ߵ�˳���ͨ��¼�����б�" << endl;
	list.Reverse();
	list.PrintList();
	//PHONEBOOK x = list.Delete(3);
	//cout << "ɾ��Ԫ�أ�" << endl;
	//x.print();
	//cout << "ͨѶ�������б�" << endl;
	//list.PrintList();
	//int p = list.Locate(record);
	//cout << "phonix��λ���ǣ�" << p << endl;
	///*list.GetLength();*/
	//list.~LinkList();
	//return 0;
}
