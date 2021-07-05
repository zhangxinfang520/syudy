//@Time : 2021-07-05 10:44
//@Author: zxf_ҪŬ��
//@File : 05.h
// ���õ������㷨
#include "iostream"
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> create_date(){
    vector<int> v ;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(5);
    return v;
}

void printV(vector<int> &nums){
    for(int num:nums){
        cout << num << " ";
    }
    cout <<endl;
}

void test01(){
    //���������� ����Ԫ���ۼ��ܺ�
    //- accumulate`      // ��������Ԫ���ۼ��ܺ�
    //- `fill`                 // �����������Ԫ��
    vector<int> v = create_date();
    int total = accumulate(v.begin(),v.end(),0);
    cout <<total << endl;
}
void test02(){
    //���ָ��Ԫ��
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end(),100);
    printV(v);
}

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test03(){
    //���ϳ��ò���

    //set_intersection        // �����������Ľ���
    //set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // ���������ϵĽ���
    // **ע��:�������ϱ�������������**
    // beg1 ����1��ʼ������
    // end1 ����1����������
    // beg2 ����2��ʼ������
    // end2 ����2����������
    // dest Ŀ��������ʼ������
    vector<int> v1 =create_date();
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);

    vector<int> target;
    target.resize(min(v1.size(),v2.size()));

    vector<int>::iterator it = set_intersection(v1.begin(),
                                                v1.end(),v2.begin(), v2.end(),target.begin());
    for_each(target.begin(), it, myPrint());
	cout << endl;
}

void test04(){
    //���������ϵĲ���
    //`set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // ���������ϵĲ���
    // **ע��:�������ϱ�������������**
    // beg1 ����1��ʼ������
    // end1 ����1����������
    // beg2 ����2��ʼ������
    // end2 ����2����������
    // dest Ŀ��������ʼ������
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//ȡ���������ĺ͸�Ŀ���������ٿռ�
	vTarget.resize(v1.size() + v2.size());

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	vector<int>::iterator itEnd =
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
	//- �󲢼����������ϱ������������
    //- Ŀ���������ٿռ���Ҫ**�����������**
    //- set_union����ֵ���ǲ��������һ��Ԫ�ص�λ��
}

void test05(){
    //���������ϵĲ
    //`set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
    // ���������ϵĲ
    // **ע��:�������ϱ�������������**
    // beg1 ����1��ʼ������
    // end1 ����1����������
    // beg2 ����2��ʼ������
    // end2 ����2����������
    // dest Ŀ��������ʼ������
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//ȡ��������ϴ��ֵ��Ŀ���������ٿռ�
	vTarget.resize( max(v1.size() , v2.size()));

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	cout << "v1��v2�ĲΪ�� " << endl;
	vector<int>::iterator itEnd =
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;


	cout << "v2��v1�ĲΪ�� " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
	//- �����������ϱ������������
    //- Ŀ���������ٿռ���Ҫ��**��������ȡ�ϴ�ֵ**
    //- set_difference����ֵ���ǲ�����һ��Ԫ�ص�λ��
}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
}



