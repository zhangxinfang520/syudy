//@Time : 2021-06-17 9:43
//@Author: zxf_要努力
//@File : 05.h
// 引用的本质：在c++内部实现是一个指针常量

#include <iostream>
using namespace std;

void fun(int &ref){
    ref = 100;

}

int main(){
    int a = 10;
    //自动转化为 int* const ref = &a;指针常量
    //指向不可改 也说明引用不可更改
    int &ref = a;
    ref = 20; //内部发现ref是引用自动把我们转化为 *ref = 20

    cout<<"a: "<< a <<endl;
    cout<<"ref:"<< ref << endl;

    fun(ref);
    cout<<"ref:"<< ref << endl;
}
