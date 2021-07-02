//@Time : 2021-06-30 11:46
//@Author: zxf_要努力
//@File : 05.h
//str的赋值方式
#include "iostream"
#include "algorithm"
#include <vector>
using namespace std;

/*
* `string& operator=(const char* s);`             //char*类型字符串 赋值给当前的字符串
* `string& operator=(const string &s);`         //把字符串s赋给当前的字符串
* `string& operator=(char c);`                          //字符赋值给当前的字符串
* `string& assign(const char *s);`                  //把字符串s赋给当前的字符串
* `string& assign(const char *s, int n);`     //把字符串s的前n个字符赋给当前的字符串
* `string& assign(const string &s);`              //把字符串s赋给当前字符串
* `string& assign(int n, char c);`                  //用n个字符c赋给当前字符串


 */
void test(){
    char  *s =  "zxf";
    string str1 = s;
    cout << str1 <<endl;
    string str2;
    str2 = "wmx";
    cout << str2 <<endl;
    string str3 = str2;
    cout << str3 <<endl;
    string str4;
    str4.assign(s);
    cout << str4 <<endl;
    string str5;
    str5.assign(s,2);
    cout << str5 <<endl;
    string str6;
    str6.assign(str5);
    cout << str6 <<endl;
    string str7;
    str7.assign(3,'zxf_love_wmx');
    cout<<str7<<endl;
}

int main(){
    test();
}