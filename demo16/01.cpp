//@Time : 2021-07-03 13:20
//@Author: zxf_要努力
//@File : 01.h
//stack 操作stack是一种**先进后出**(First In Last Out,FILO)的数据结构，它只有一个出口

#include "iostream"
#include <stack>
#include "algorithm"

using namespace std;

void test(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        //输出栈顶元素
        cout <<"栈顶元素为：" << s.top()<<endl;
        //弹出栈顶元素
        s.pop();
    }
    cout<<"栈的大小" << s.size() <<endl;


}
int main(){
    test();
}


