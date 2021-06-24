//@Time : 2021-06-23 16:11
//@Author: zxf_要努力
//@File : 02.h
//析构函数和纯析构函数

//多态使用时，如果子类中有属性开辟到堆区，
//那么父类指针在释放时无法调用到子类的析构代码
#include "iostream"
using namespace std;
#include <string>

class Animal{
public:
    Animal(){
        cout <<"Animal 的构造函数"<<endl;
    }
    virtual void say()=0;

    // 如果不是纯析构函数通过父类创建子类对象 无法调用子类的析构函数
//    ~Animal(){
//        cout<<"Animal 的析构函数"<<endl;
//    }
    //纯析构函数 也要有实现的
    virtual ~Animal()=0;
};

Animal::~Animal(){
    cout<<"Animal 的纯析构函数"<<endl;
}

class Cat:public Animal{
public:
    Cat(string name){
        cout <<"子类 的构造函数"<<endl;
        this->name = new string(name);
    }
    void say(){
        cout<<"子类实现父类的虚构函数"<<endl;
    }
    ~Cat(){
        if (name==NULL){
            delete name;
            name = NULL;
        }
        cout<<"子类的析构函数"<<endl;
    }
    string *name;
};

void test(){
    Animal *a = new Cat("Tom");
    a->say();
    //通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
    delete a;
}
int main(){
    test();
}


