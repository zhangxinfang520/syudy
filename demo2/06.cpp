//@Time : 2021-06-17 9:55
//@Author: zxf_要努力
//@File : 06.h
//常量引用
#include <iostream>
using namespace std;

void show(const int &a){
    //a = 1000; 添加const之后 无法修改
    cout<<a<<endl;
}

int main(){
    //常量引用
    //使用场景 用来修饰形参，防止误操作
    int a = 10;
    show(a);
    //int &ref = 10; 这一行代码不规范 引用必须引一块合法的内存空间
    //加上const 之后编译器将代码修改为 int temp=10；const int &ref = temp
    const int &ref = 10;

}

