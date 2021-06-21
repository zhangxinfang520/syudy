//@Time : 2021-06-21 15:13
//@Author: zxf_要努力
//@File : 09.h
//函数调用运算符重载
#include "iostream"
using namespace std;
class MyPrint{
public:
    void operator()(string text){
        cout<<text<<endl;
    }
};

class myAdd{
public:
    int operator()(int a,int b){
        return a+b;
    }
};
void test01(){
   MyPrint myFunc;
   myFunc("hello world");
}

void test02(){
    cout<<myAdd()(1,2)<<endl;
}
int main(){
    test01();
    test02();
}

