//@Time : 2021-07-03 0:11
//@Author: zxf_要努力
//@File : 07.h
//vector预留空间
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


void test(){
    vector<int> v;
    v.reserve(100000);
    int num = 0;
    int* p = NULL;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i);
        if(p!=&v[0]){
            p = &v[0];
            num++;
        }
    }
    cout << "num:" << num << endl;
}
int main(){
    test();
}


