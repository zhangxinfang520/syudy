//@Time : 2021-07-02 23:48
//@Author: zxf_ҪŬ��
//@File : 06.h
//vector��������
#include "iostream"
#include "algorithm"
#include <vector>
using namespace std;

//ʵ������������Ԫ�ؽ��л���  wap(vec);`  // ��vec�뱾���Ԫ�ػ���

void printVector(vector<int> &v){
    for(vector<int>::iterator p =v.begin(); p!=v.end();p++){
        cout<< *p<<" ";
    }
    cout<<endl;
}
void test(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	//��������
	cout << "������" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

}
void test02()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	v.resize(3);

	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	//�����ڴ�
	vector<int>(v).swap(v); //��������

	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
}

int main(){
    test();
    test02();
}
