//@Time : 2021-06-17 10:24
//@Author: zxf_ҪŬ��
//@File : 01.h
// ����ѧϰ
//����վλ
#include <iostream>

using namespace std;

//ռλ���� �ֽ׶��ò���
void func(int a,int = 10){
    cout << "����ռλ��" <<endl;
}

int main(){
    int a = 10 ;
    func(a);
    system("pause");
    return 0;
    
}

