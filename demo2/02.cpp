//
// Created by lenovo on 2021-06-16.
//

#include <iostream>
using namespace std;
//栈区数据 由编译器管理和开辟
//非法访问
int *func(){
    int a = 10;//局部变量 存放在栈区 栈区的数据在函数执行完后自动释放
    return &a;//返回局部变量地址
}

//需要开学常量
int * func1(){
    //指针 本质也是局部变量 放在栈上 指针保存的数据是放在堆区
    int *p = new int(10);//放到堆区

    return p;
}

//在堆区开辟数组
void func2(){
    //创建整形数据的数组 在堆区
    int *arr = new int[10];
    for(int i=0;i<10;++i){
        arr[i] =  i + 10;
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<endl;
    }
    //释放数组
    delete[] arr;
}

int main(){
    func2();
    int *p = func();
    printf("%d\n",*p);
    printf("%d\n",*p);
    cout << *p <<endl;

    int *p1 = func1();
    printf("%d\n",*p1);
    printf("%d\n",*p1);
    //堆区的数据由程序员管理
    delete p1;
    printf("%d\n",*p1);

    return 0;
}