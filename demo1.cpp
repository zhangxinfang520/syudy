//
// Created by lenovo on 2021-06-07.
//
#include "iostream"
#include "demo1_fun.h"
#include "demo1/study_01.h"
#include "project01/pro01.h"

using namespace std;

int main2() {

	//1��ָ��Ķ���
	int a = 10; //�������ͱ���a

	//ָ�붨���﷨�� �������� * ������ ;
	int *p;

	//ָ�������ֵ
	p = &a; //ָ��ָ�����a�ĵ�ַ
	cout << &a << endl; //��ӡ����a�ĵ�ַ
	cout << p << endl;  //��ӡָ�����p

	//2��ָ���ʹ��
	//ͨ��*����ָ�����ָ����ڴ�
	cout << "*p = " << *p << endl;

	system("pause");

	return 0;
}
//����ָ����ռ�Ŀռ�

int main3(){
    int a = 10;
    int *p;
    p = &a;
    cout<<*p<<endl; //������
    cout << sizeof(p) <<endl;
    cout << sizeof(char *) <<endl;
    cout << sizeof(float *)<< endl;
    cout << sizeof(double *) <<endl;
    return 0;
}

//��ָ��
int main4(){
    int *p =NULL;
    //��ָ��ָ�����ָ���ڴ��б��Ϊ0�Ŀռ� �޷�����
    cout << *p<<endl;
}

//Ұָ�� ָ�����ָ��Ƿ����ڴ�ռ�
int main5(){
    //ָ�����pָ���ڴ��ַ���Ϊ0x1100�Ŀռ�
    int *p = (int *)0x1100;
    //����Ұָ�뱨��
    cout<< *p <<endl;
}

//const ����ָ��
/*
 * const ����ָ�� --����ָ��
 * const ���γ��� -- ָ�볣��
 *
 * */
// const ����
int main6(){
    int a = 10;
    int b = 100;
    //const ���ε���ָ�� ָ��ָ������޸� ָ��ָ���ֵ���ɸ���
    const int *p1 = &a;
    p1 = &b; //������Բ����޸� ������
    //*p = 100; //�������
    cout<< *p1 <<endl;

    //const���ε��ǳ�����ָ��ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը���
    int  * const p2 = &a;
    //p2 = &b;//�����޷��޸�
    *p2 = 100;
    cout << *p2<<endl;

    //const ����ͬʱ����ָ���ָ��ֵ
    const int * const p3 = &a;
    //ʲô���������޸�

}
//ָ�������
int main7(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int *p = arr;
    cout<< "a " << arr[0] << endl;
    cout<< "b: " << *p << endl;
//    system("pause");
    for (int j=0;j<10;j++ ) {
        cout << arr[j] << endl;
        p++;
    };
    return 0;
}

//��ַ���ݻ�ı�ֵ
//��ͨ����
int swap(int num1,int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
//��ַ����
int swap2(int *p1,int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main8(){
    int a = 10;
    int b = 20;
    swap(a,b);
    cout <<a<<","<< b<<endl;
    swap2(&a,&b);
    cout <<a<<","<< b<<endl;
}

//�����ⲿ�ļ�

int main9(){
    int arr[] = {5,8,4,2,6,4154,13,64,52,1};
    int n = sizeof(arr)/ sizeof(int);
    bubleSort(arr,n);
    printArray(arr,n);
}


// �����ṹ��
//c++�� ���������������� ֱ��Ϊ��������ĵ�ַ ����������ᷢʲô�ı�

struct person {
    string name;
    int age;
    string address;
};

int main10(){
    struct person arr[2] = {
            {"���η�",23,"����"},
            {"���η�01",23,"����"},
    };

    int len = sizeof(arr) / sizeof(person);
    for (int j=0 ;j<len;j++){
        cout<< arr[j].name<<endl;
        cout<< arr[j].age<<endl;
        cout<< arr[j].address<<endl;
    }
};

int main(){

    start();
}