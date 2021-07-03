//@Time : 2021-07-03 17:38
//@Author: zxf_ҪŬ��
//@File : 06.h
//set �� multiset ����
/*
 set���������������ظ���Ԫ��
 multiset�������������ظ���Ԫ��
 * set������������ʱ��insert
* set�����������ݵ����ݻ��Զ�����
 */
#include "iostream"
#include "set"
#include "algorithm"

using namespace std;

void printSet(set<int> & s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

set<int>  getset(){
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(15);
    s1.insert(10);

    return s1;
}

void test(){
    //set �Ĺ���
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(15);
    s1.insert(10);
    printSet(s1);

    set<int> s2(s1);
    printSet(s2);

    set<int> s3;
    s3 = s2;
    printSet(s3);
}
void test01(){
    //set�Ĵ�С�ͽ���
    set<int> s = getset();
    printSet(s);
    if (s.empty()){
        cout << "s1Ϊ��" << endl;
    }else{
        cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ�� " << s.size() << endl;
    }
}

void test02(){
    //set ����
    set<int> s1 = getset();
    printSet(s1);
    set<int> s2;
    s2.insert(1);
    printSet(s2);
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}

void test03(){
    //set�������в������ݺ�ɾ������
    //* `insert(elem);`           //�������в���Ԫ�ء�
    //* `clear();`                    //�������Ԫ��
    //* `erase(pos);`              //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
    //* `erase(beg, end);`    //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
    //* `erase(elem);`            //ɾ��������ֵΪelem��Ԫ��

    set<int> s1 = getset();
    //ɾ��
    s1.erase(s1.begin());
    printSet(s1);
    s1.erase(30);
	printSet(s1);
	//���
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
}

void test04(){
    //��set�������в��������Լ�ͳ������
    //* `find(key);`                  //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
    //* `count(key);`                //ͳ��key��Ԫ�ظ���
    set<int> s1 = getset() ;
    set<int>::iterator pos = s1.find(30);
    if(pos != s1.end()){
        cout <<"�Ҳ���Ԫ�أ� "<<*pos <<endl;
    } else{
        cout <<"δ�Ҳ���Ԫ�أ� "<<endl;
    }
    //ͳ��
    int num = s1.count(20);
    cout <<"num: " <<num<<endl;

}
int main(){
//test03();
    test04();
}


