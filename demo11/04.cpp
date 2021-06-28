//gbk
// @Time : 2021-06-28 14:06
//@Author: zxf_要努力
//@File : 04.h
//函数模板和普通函数的调用规则
/*
 1. 如果函数模板和普通函数都可以实现，优先调用普通函数
 2. 可以通过空模板参数列表来强制调用函数模板
 3. 函数模板也可以发生重载
 4. 如果函数模板可以产生更好的匹配,优先调用函数模板
 */
#include "iostream"
using namespace std;

void swapa(int a,int b){
    cout<<"普通函数"<<endl;
    cout<<"1"<<endl;
}

template<typename T>
void swapa(T a,T b){
    cout<<"模板函数"<<endl;
}
template<typename T>
void swapa(T a,T b,T c){
    cout<<"模板函数重载"<<endl;
}

void test(){
    int a = 10;
    int b = 10;
    char c = 'a';
    char d = 'a';
    swapa(a,b);//优先调用普通函数
    swapa<>(a,b);//强制调用目标函数
    swapa<>(a,b,100);//模板函数重载
    swapa(c,d);


}
int main(){
    test();
}