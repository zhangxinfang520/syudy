//
// Created by lenovo on 2021-06-07.
//
#include "iostream"
#include "demo1_fun.h"
#include "demo1/study_01.h"
#include "project01/pro01.h"

using namespace std;

int main2() {

	//1、指针的定义
	int a = 10; //定义整型变量a

	//指针定义语法： 数据类型 * 变量名 ;
	int *p;

	//指针变量赋值
	p = &a; //指针指向变量a的地址
	cout << &a << endl; //打印数据a的地址
	cout << p << endl;  //打印指针变量p

	//2、指针的使用
	//通过*操作指针变量指向的内存
	cout << "*p = " << *p << endl;

	system("pause");

	return 0;
}
//计算指针所占的空间

int main3(){
    int a = 10;
    int *p;
    p = &a;
    cout<<*p<<endl; //解引用
    cout << sizeof(p) <<endl;
    cout << sizeof(char *) <<endl;
    cout << sizeof(float *)<< endl;
    cout << sizeof(double *) <<endl;
    return 0;
}

//空指针
int main4(){
    int *p =NULL;
    //空指针指针变量指向内存中编号为0的空间 无法访问
    cout << *p<<endl;
}

//野指针 指针变量指向非法的内存空间
int main5(){
    //指针变量p指向内存地址编号为0x1100的空间
    int *p = (int *)0x1100;
    //访问野指针报错
    cout<< *p <<endl;
}

//const 修饰指针
/*
 * const 修饰指针 --常量指针
 * const 修饰常量 -- 指针常量
 *
 * */
// const 修饰
int main6(){
    int a = 10;
    int b = 100;
    //const 修饰的是指针 指针指向可以修改 指针指向的值不可更改
    const int *p1 = &a;
    p1 = &b; //这个可以操作修改 不报错
    //*p = 100; //这个报错
    cout<< *p1 <<endl;

    //const修饰的是常量，指针指向不可以改，指针指向的值可以更改
    int  * const p2 = &a;
    //p2 = &b;//错误无法修改
    *p2 = 100;
    cout << *p2<<endl;

    //const 可以同时修饰指针和指针值
    const int * const p3 = &a;
    //什么都不可以修改

}
//指针和数组
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

//地址传递会改变值
//普通传递
int swap(int num1,int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
//地址传递
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

//操作外部文件

int main9(){
    int arr[] = {5,8,4,2,6,4154,13,64,52,1};
    int n = sizeof(arr)/ sizeof(int);
    bubleSort(arr,n);
    printArray(arr,n);
}


// 操作结构体
//c++中 如果传递数组的名称 直接为传递数组的地址 对数组操作会发什么改变

struct person {
    string name;
    int age;
    string address;
};

int main10(){
    struct person arr[2] = {
            {"张鑫方",23,"河南"},
            {"张鑫方01",23,"河南"},
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