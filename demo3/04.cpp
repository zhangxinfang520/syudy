//@Time : 2021-06-17 11:04
//@Author: zxf_ҪŬ��
//@File : 04.h
// ���õĸ߼��÷�
#include <iostream>
using namespace std;

void func(int &a){
    cout << "func (int &a) ���� " << endl;
}
void func(const int &a){
    cout << "func (const int &a) ���� " << endl;
}

int main(){
    int a = 10;
    func(a);
    func(10);
}

