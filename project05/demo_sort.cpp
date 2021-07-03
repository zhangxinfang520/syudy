//@Time : 2021-07-03 14:55
//@Author: zxf_要努力
//@File : demo_sort.h
// 将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
//
//排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
#include "iostream"
#include <list>
#include <string>
#include "algorithm"

using namespace std;

class Person {
public:
    Person(string name,int age,int height){
        this->name = name;
        this->age = age;
        this->height = height;
    }
    string name;
    int age;
    int height;
};

bool ComparePerson(Person &a,Person &b){
    if(a.age==b.age){
        return a.height > b.height;
    }else{
        return a.age < b.age;
    }
}

void test(){
    Person p("zxf",18,198);
    Person p3("zxf",18,200);
    Person p1("zxf",13,169);
    Person p2("zxf",14,170);
    list<Person> l;
    l.push_back(p);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++) {
		cout << "姓名： " << it->name<< " 年龄： " << it->age
              << " 身高： " << it->height << endl;
	}
	cout << "---------------------------------" << endl;
    l.sort(ComparePerson);
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++) {
		cout << "姓名： " << it->name<< " 年龄： " << it->age
              << " 身高： " << it->height << endl;
	}
}
int main(){
    test();
}

