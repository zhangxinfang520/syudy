//@Time : 2021-06-20 17:04
//@Author: zxf_要努力
//@File : 07.h
// 空指针 可以调用成员函数
#include "iostream"
//C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
//如果用到this指针，需要加以判断保证代码的健壮性
using namespace std;
class Person{
public:
    int age;
    void ShowClassName(){
        cout<<"我是person类"<<endl;
    }

    void Show(){
        if (this==NULL){
            return;
        }
        cout << age << endl;
    }
};

void test(){
    Person * p =NULL;

    p->ShowClassName();
    p->Show();

}
int main(){
    test();
}

