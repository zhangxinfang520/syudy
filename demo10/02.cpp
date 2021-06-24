//@Time : 2021-06-24 11:14
//@Author: zxf_要努力
//@File : 02.h
//读文件
#include <iostream>
using namespace std;
#include <fstream>
#include <string>


void test(){
 //1.包含头文件
 // 2.创建流对象
  ifstream ifs;
 // 3.打开文件并判断文件是否打开成功
 string file_path = "../demo10/zxf.txt";
 ifs.open(file_path,ios::in);
 //判断
 if (!ifs.is_open()){
     cout<<"open file failed";
     return;
 }
 // 4.读数据
 //第一种方式
// char buff[1024] = {0};
// while(ifs >> buff){
//     cout<<buff<<endl;
// }
 //第二方式
// char buf[1024] = {0};
// while(ifs.getline(buf,sizeof(buf))){
//     cout <<buf<<endl;
// }
//第三种
//string buf;
// while(getline(ifs,buf)){
//     cout<<buf<<endl;
// }
char c;
 while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

 // 5.关闭文件
 ifs.close();
}

int main(){
    test();
}

