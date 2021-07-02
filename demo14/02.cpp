//@Time : 2021-06-30 16:23
//@Author: zxf_要努力
//@File : 02.h
//vector 赋值操作
#include "iostream"
#include <vector>
#include "algorithm"
using namespace std;
/*
* vector& operator=(const vector &vec);/重载等号操作符
* assign(beg, end);       //将[beg, end)区间中的数据拷贝赋值给本身。
* assign(n, elem);        //将n个elem拷贝赋值给本身
 */

void printVector(vector<int> &v){
    for (vector<int>::iterator a= v.begin(); a!=v.end() ; a++) {
        cout << *a <<endl;
    }

}
void test(){
    vector<int> a;
    a.push_back(1);
    printVector(a);
    vector<int> b = a;
    printVector(b);

}

int main(){
 test();
}

