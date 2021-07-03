//@Time : 2021-07-03 18:13
//@Author: zxf_要努力
//@File : 07.h
//set 和multiset的区别
#include "iostream"
#include <set>
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
void test01(){
    //set<int> s = getset();

    //* set不可以插入重复数据，而multiset可以
    //* set插入数据的同时会返回插入结果，表示插入是否成功
    //* multiset不会检测数据，因此可以插入重复数据
    set<int> s;
    pair<set<int>::iterator,bool> ret = s.insert(10);
    if (ret.second){
        cout << "insert true" << endl;
    } else{
        cout << "insert error" << endl;
    }

    ret = s.insert(10);
    if (ret.second){
        cout << "insert true" << endl;
    } else{
        cout << "insert error" << endl;
    }
    //multiset
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for (multiset<int>::iterator it=ms.begin();it!=ms.end();it++) {
        cout << *it <<" ";
    }
    cout << endl;

}

int main(){
    test01();
}

