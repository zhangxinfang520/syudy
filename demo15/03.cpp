//@Time : 2021-07-03 11:01
//@Author: zxf_要努力
//@File : 03.h
//deque 的大小操作
#include "iostream"
#include "algorithm"
#include <deque>
using namespace std;

void printDeque(const deque<int> &v){
    for ( deque<int>::const_iterator p= v.begin() ; p!= v.end() ; p++) {
        cout << *p << "";
    }
    cout << endl;
}

void test(){
    deque<int> d1;
    for (int i = 0; i < 10 ; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);
    if(d1.empty()){
        cout<<"deque is empty" <<endl;
    }else{
        cout << " deque size" << d1.size()<<endl;
        d1.resize(15);
        printDeque(d1);
        d1.resize(13,1);
        printDeque(d1);
        d1.resize(5,0);
        printDeque(d1);
    }
}
int main(){
    test();
}

