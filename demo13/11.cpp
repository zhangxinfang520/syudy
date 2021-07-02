//@Time : 2021-06-30 14:44
//@Author: zxf_要努力
//@File : 11.h
//string 子串
/*
 `string substr(int pos = 0, int n = npos) const;`   //返回由pos开始的n个字符组成的字符串
 */
#include "iostream"
#include <string>
using namespace std;

void test(){
    string str = "abcdefg";
    string substr = str.substr(1,3);
    cout << substr<<endl;

    string email = "zhangxinfang@qq.com";
    int pos = email.find("@");
    string name = email.substr(0,pos);
    cout<<name<<endl;
}
int main(){
    test();
}

