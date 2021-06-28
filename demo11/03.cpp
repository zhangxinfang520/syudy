//@Time : 2021-06-28 13:51
//@Author: zxf_要努力
//@File : 03.h
// 普通函数和目标函数的区别
/*
普通函数调用时可以发生自动类型转换（隐式类型转换）
函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
如果利用显示指定类型的方式，可以发生隐式类型转换
*/
#include "iostream"
using namespace std;

int myAdd(int a,int b){
   return a+b;
}

template<class T>
T templateAdd(T a,T b){
    return a+b;
}

void test(){
    int a = 10;
    int b = 0;
    char c = 'a';
    cout << myAdd(a,b)<<endl;
    cout << myAdd(a,c)<<endl;
    cout<<"--------"<<endl;
    cout << templateAdd(a,b)<<endl;

    //cout << templateAdd(a,c)<<endl; 不能显示转换
    cout << templateAdd<int>(a,c)<<endl;

}
int main(){
    test();
}