//@Time : 2021-06-24 10:56
//@Author: zxf_要努力
//@File : 01.h
//操作文件 需要导入头文件
#include "iostream"
#include <fstream>
using namespace std;

void test(){
    string txt_path = "F:/c++/demo10/zxf.txt";
    ofstream ofs;
    ofs.open(txt_path,ios::app);
    ofs<<"张鑫方要努力\n";
    ofs<<"张鑫方要努力" <<endl;
    ofs<<"张鑫方要努力" <<endl;
    ofs.close();
}
int main(){
    test();
}


