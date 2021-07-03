//@Time : 2021-07-03 17:38
//@Author: zxf_要努力
//@File : 06.h
//set 和 multiset 区别
/*
 set不允许容器中有重复的元素
 multiset允许容器中有重复的元素
 * set容器插入数据时用insert
* set容器插入数据的数据会自动排序
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
    //set 的构造
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
    //set的大小和交换
    set<int> s = getset();
    printSet(s);
    if (s.empty()){
        cout << "s1为空" << endl;
    }else{
        cout << "s1不为空" << endl;
		cout << "s1的大小为： " << s.size() << endl;
    }
}

void test02(){
    //set 交换
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
    //set容器进行插入数据和删除数据
    //* `insert(elem);`           //在容器中插入元素。
    //* `clear();`                    //清除所有元素
    //* `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
    //* `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    //* `erase(elem);`            //删除容器中值为elem的元素

    set<int> s1 = getset();
    //删除
    s1.erase(s1.begin());
    printSet(s1);
    s1.erase(30);
	printSet(s1);
	//清空
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
}

void test04(){
    //对set容器进行查找数据以及统计数据
    //* `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    //* `count(key);`                //统计key的元素个数
    set<int> s1 = getset() ;
    set<int>::iterator pos = s1.find(30);
    if(pos != s1.end()){
        cout <<"找不到元素： "<<*pos <<endl;
    } else{
        cout <<"未找不到元素： "<<endl;
    }
    //统计
    int num = s1.count(20);
    cout <<"num: " <<num<<endl;

}
int main(){
//test03();
    test04();
}


