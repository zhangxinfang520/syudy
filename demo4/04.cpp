//@Time : 2021-06-18 20:23
//@Author: zxf_要努力
//@File : 04.h
//成员变量的联系
#include <string>
#include <iostream>
using namespace std;

class Person{
private:
    string n_Name;
    int n_Age;
    string Lover;
public:
    void setName(string name){
        n_Name = name;
    }
    void getName(){
        cout<<n_Name<<endl;
    }
    void setAge(int age){
        if (age> 150 or age<0){
            cout <<"请输入正确的信息"<<endl;
            return;
        }
        n_Age = age;
    }
    void getAge(){
        cout<<n_Age<<endl;
    }
    void setLover(string lover){
        Lover = lover;
    }
    void getLover(){
        cout<<Lover<<endl;
    }
};

int main(){
    Person p;
    p.setName("zxf");
    p.getName();
    p.setAge(160);
    p.getAge();
    p.setAge(10);
    p.getAge();
    p.setLover("wmx");
    p.getLover();


}

