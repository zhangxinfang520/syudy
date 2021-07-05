//@Time : 2021-07-04 18:26
//@Author: zxf_要努力
//@File : 02.h
//常用查找算法
#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

//- `find`                     //查找元素
//- `find_if`               //按条件查找元素
//- `adjacent_find`    //查找相邻重复元素
//- `binary_search`    //二分查找法
//- `count`                   //统计元素个数
//- `count_if`             //按条件统计元素个数
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
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    // beg 开始迭代器
    // end 结束迭代器
    // value 查找的元素
    vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	vector<int>::iterator it = find(v.begin(),v.end(),5);
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到:" << *it << endl;
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
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << it->name << " 年龄: " << it->age << endl;
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

	//创建数据
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
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << it->name << " 年龄: " << it->age << endl;
	}
}

void test04(){
    //查找相邻元素
    //`adjacent_find(iterator beg, iterator end);  `
    // 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
    // beg 开始迭代器
    // end 结束迭代器
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
    //查找指定元素是否存在
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
    //统计元素个数
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    int cot = count(v.begin(),v.end(),3);
    cout << "3的个数为： " << cot << endl;
}

class Greater4{
public:
    bool operator()(int val){
        return val > 4 ;
    }
};

void test07(){
    //按条件 查找
     vector<int> v;
    v.push_back(1);
    v.push_back(55);
    v.push_back(5);
    v.push_back(4);
    v.push_back(4);

    int num = count_if(v.begin(),v.end(),Greater4());
     cout << "大于4的个数为： " << num << endl;
}

int main(){
//test02();
    //test03();
    //test04();
    //test05();
    //test06();
    test07();
}

