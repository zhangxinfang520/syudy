//gbk
// @Time : 2021-06-28 14:06
//@Author: zxf_ҪŬ��
//@File : 04.h
//����ģ�����ͨ�����ĵ��ù���
/*
 1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
 2. ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
 3. ����ģ��Ҳ���Է�������
 4. �������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
 */
#include "iostream"
using namespace std;

void swapa(int a,int b){
    cout<<"��ͨ����"<<endl;
    cout<<"1"<<endl;
}

template<typename T>
void swapa(T a,T b){
    cout<<"ģ�庯��"<<endl;
}
template<typename T>
void swapa(T a,T b,T c){
    cout<<"ģ�庯������"<<endl;
}

void test(){
    int a = 10;
    int b = 10;
    char c = 'a';
    char d = 'a';
    swapa(a,b);//���ȵ�����ͨ����
    swapa<>(a,b);//ǿ�Ƶ���Ŀ�꺯��
    swapa<>(a,b,100);//ģ�庯������
    swapa(c,d);


}
int main(){
    test();
}