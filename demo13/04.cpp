//@Time : 2021-06-30 11:33
//@Author: zxf_要努力
//@File : 04.h
//STL 常用容器
#include "iostream"
#include <vector>
#include "algorithm"
#include <string>
using namespace std;


void test(){
    //* `string();`          				//创建一个空的字符串 例如: string str;
    //  `string(const char* s);`	        //使用字符串s初始化
    //* `string(const string& str);`    //使用一个string对象初始化另一个string对象
    //* `string(int n, char c);`

    const char * str = "zxf";
    string s1;//创建空字符串，调用无参构造函数
    cout << "str1 = " << s1 << endl;
    string s2(str);
    cout << "str2 = " << s2 << endl;
    string s3(s2);
    cout << "str3 = " << s3 << endl;
    string s4(10,'bbbb');
    cout << "str4 = " << s4 << endl;

}
int main(){
    test();
}
