//@Time : 2021-06-17 11:04
//@Author: zxf_要努力
//@File : 04.h
// 引用的高级用法
#include <iostream>
using namespace std;

void func(int &a){
    cout << "func (int &a) 调用 " << endl;
}
void func(const int &a){
    cout << "func (const int &a) 调用 " << endl;
}

int main(){
    int a = 10;
    func(a);
    func(10);
}

