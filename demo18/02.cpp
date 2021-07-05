//@Time : 2021-07-04 18:26
//@Author: zxf_ҪŬ��
//@File : 02.h
//���ò����㷨
#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

//- `find`                     //����Ԫ��
//- `find_if`               //����������Ԫ��
//- `adjacent_find`    //���������ظ�Ԫ��
//- `binary_search`    //���ֲ��ҷ�
//- `count`                   //ͳ��Ԫ�ظ���
//- `count_if`             //������ͳ��Ԫ�ظ���
class Person{
public:
    Person(string name,int age){
        this-> name = name;
        this-> age = age;
    }
    bool operator==(const Person &p){
        if(this->name == p.name && this->age ==p.age){
            return true;
        }
        return false;
    }
public:
    string name;
    int age;
};

void test01(){
    //`find(iterator beg, iterator end, value);  `
    // ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
    // beg ��ʼ������
    // end ����������
    // value ���ҵ�Ԫ��
    vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	vector<int>::iterator it = find(v.begin(),v.end(),5);
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�:" << *it << endl;
	}

}

void test02(){
    vector<Person> v;
    Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�����:" << it->name << " ����: " << it->age << endl;
	}
}

class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.age > 20;
	}

};

void test03() {

	vector<Person> v;

	//��������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�����:" << it->name << " ����: " << it->age << endl;
	}
}

void test04(){
    //��������Ԫ��
    //`adjacent_find(iterator beg, iterator end);  `
    // ���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ�����
    // beg ��ʼ������
    // end ����������
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    vector<int>::iterator it = adjacent_find(v.begin(),
                                             v.end());
    if( it!=v.end()){
        cout<< "find adjacent_find " << *it <<endl;
    }else{
        cout << "no find "<<endl;
    }
}

void test05(){
    //����ָ��Ԫ���Ƿ����
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    bool it = binary_search(v.begin(),v.end(),4);
    if( it){
        cout << "find it "  <<endl;
    }else{
        cout <<" not found everything  " << endl;
    }
}

void test06(){
    //ͳ��Ԫ�ظ���
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    int cot = count(v.begin(),v.end(),3);
    cout << "3�ĸ���Ϊ�� " << cot << endl;
}

class Greater4{
public:
    bool operator()(int val){
        return val > 4 ;
    }
};

void test07(){
    //������ ����
     vector<int> v;
    v.push_back(1);
    v.push_back(55);
    v.push_back(5);
    v.push_back(4);
    v.push_back(4);

    int num = count_if(v.begin(),v.end(),Greater4());
     cout << "����4�ĸ���Ϊ�� " << num << endl;
}

int main(){
//test02();
    //test03();
    //test04();
    //test05();
    //test06();
    test07();
}

