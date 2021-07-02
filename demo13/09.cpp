//@Time : 2021-06-30 14:01
//@Author: zxf_要努力
//@File : 09.h
// 字符串的遍历
#include "iostream"
#include <string>
using namespace std;
/*
 访问方式
    `char& operator[](int n); `     //通过[]方式取字符
    `char& at(int n);   `            //通过at方法获取字符
 */
void test(){
    string str = "zxf_yaonuli";
    for (int i = 0; i < str.size(); ++i) {
        cout << str[i] <<" ";
    }
    cout<<endl;
    //字符串的修改
    str[0] = 'w';
    str[1] = 'm';
    str.at(2) = 'x';

    for (int i = 0; i <str.size() ; ++i) {
        cout<<str.at(i)<< " ";
    }
    cout<<endl;
}
int main(){
    test();
}

