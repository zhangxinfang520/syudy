//@Time : 2021-06-30 14:10
//@Author: zxf_要努力
//@File : 10.h
//string插入和删除
// 对string字符串进行插入和删除字符操作
#include "iostream"
#include <string>
using namespace std;

/*
 * `string& insert(int pos, const char* s);  `                //插入字符串
* `string& insert(int pos, const string& str); `        //插入字符串
* `string& insert(int pos, int n, char c);`                //在指定位置插入n个字符c
* `string& erase(int pos, int n = npos);`                    //删除从Pos开始的n个字符
*/

void test(){
    string str = "zxf";
    char *c = "s";
    str.insert(0,c);
    cout<<str<<endl;
    str.erase(1,2);//从一号位置开始2个字符
    cout<<str<<endl;

}

int main(){
    test();
}

