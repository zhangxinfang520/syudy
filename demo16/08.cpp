//@Time : 2021-07-03 18:47
//@Author: zxf_ҪŬ��
//@File : 08.h
//pair���� ���� �ɶԳ��ֵ����ݣ����ö�����Է�����������
#include "iostream"
#include <string>
#include "algorithm"
//���鴴��
using namespace std;

void test01()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "������ " <<  p.first << " ���䣺 " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "������ " << p2.first << " ���䣺 " << p2.second << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}

