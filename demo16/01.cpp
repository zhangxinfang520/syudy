//@Time : 2021-07-03 13:20
//@Author: zxf_ҪŬ��
//@File : 01.h
//stack ����stack��һ��**�Ƚ����**(First In Last Out,FILO)�����ݽṹ����ֻ��һ������

#include "iostream"
#include <stack>
#include "algorithm"

using namespace std;

void test(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        //���ջ��Ԫ��
        cout <<"ջ��Ԫ��Ϊ��" << s.top()<<endl;
        //����ջ��Ԫ��
        s.pop();
    }
    cout<<"ջ�Ĵ�С" << s.size() <<endl;


}
int main(){
    test();
}


