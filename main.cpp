#include <iostream>

using namespace std;
// 这里主要 学习形参和实参的区别
// 参数为 形参
//函数声明
void swatch(int temp1,int temp2);

void swatch(int temp1,int temp2){
    cout<< "交换前temp1为:"<<temp1<<" ";
    cout<< "交换前temp2为:"<<temp2<<" ";
    //值 进行交换
    int temp = temp1;
    temp1 = temp2;
    temp2 = temp;
    cout<< "交换后temp1为:"<<temp1<<" ";
    cout<< "交换后temp2为:"<<temp2<<" ";
}

int main1() {

	int a = 5;
	int b = 6;
	cout<< a<<" ";
	cout<< b<<" ";
	swatch(a,b);
	cout<< a<<" ";
	cout<< b<<" ";
    return 0;
}

void test_dll(int a,int b){
    cout << a <<endl;
    cout << b <<endl;

}

int main(){
    main1();
}


