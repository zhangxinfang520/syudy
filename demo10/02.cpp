//@Time : 2021-06-24 11:14
//@Author: zxf_ҪŬ��
//@File : 02.h
//���ļ�
#include <iostream>
using namespace std;
#include <fstream>
#include <string>


void test(){
 //1.����ͷ�ļ�
 // 2.����������
  ifstream ifs;
 // 3.���ļ����ж��ļ��Ƿ�򿪳ɹ�
 string file_path = "../demo10/zxf.txt";
 ifs.open(file_path,ios::in);
 //�ж�
 if (!ifs.is_open()){
     cout<<"open file failed";
     return;
 }
 // 4.������
 //��һ�ַ�ʽ
// char buff[1024] = {0};
// while(ifs >> buff){
//     cout<<buff<<endl;
// }
 //�ڶ���ʽ
// char buf[1024] = {0};
// while(ifs.getline(buf,sizeof(buf))){
//     cout <<buf<<endl;
// }
//������
//string buf;
// while(getline(ifs,buf)){
//     cout<<buf<<endl;
// }
char c;
 while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

 // 5.�ر��ļ�
 ifs.close();
}

int main(){
    test();
}

