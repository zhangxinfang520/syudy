//@Time : 2021-07-03 10:44
//@Author: zxf_要努力
//@File : 01.h
//deque 容器操作
/*
 **概念：**Queue是一种**先进先出**(First In First Out,FIFO)的数据结构，它有两个出口
 **deque与vector区别：**
* vector对于头部的插入删除效率低，数据量越大，效率越低
* deque相对而言，对头部的插入删除速度回比vector快
* vector访问元素时的速度会比deque快,这和两者内部实现有关
 * */
#include "iostream"
#include "algorithm"
#include <deque>
using namespace std;

/*
 daque的构造方式
 */
void printDeque(const deque<int> &d){
    for (deque<int>::const_iterator v = d.begin();  v!=d.end() ; v++) {
        cout << *v <<" ";
    }
    cout << endl;
}



void test(){
    deque<int> dl;//无参数构造
    for (int i = 0; i < 10; ++i) {
        dl.push_back(i);
    }
    printDeque(dl);

    deque<int> d2(dl.begin(),dl.end());
    printDeque(d2);
    deque<int>d3(10,100);
	printDeque(d3);

	deque<int>d4 = d3;
	printDeque(d4);
}
int main(){
    test();
}



