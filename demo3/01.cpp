//@Time : 2021-06-17 10:24
//@Author: zxf_要努力
//@File : 01.h
// 函数学习
//函数站位
#include <iostream>

using namespace std;

//占位参数 现阶段用不到
void func(int a,int = 10){
    cout << "测试占位符" <<endl;
}

int main(){
    int a = 10 ;
    func(a);
    system("pause");
    return 0;
    
}

