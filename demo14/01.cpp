//@Time : 2021-06-30 15:01
//@Author: zxf_要努力
//@File : 01.h
// vector的操作
#include "iostream"
#include <vector>
#include "algorithm"
using namespace std;
//vector 的创建
/*
* `vector<T> v; `               		  //采用模板实现类实现，默认构造函数
* `vector(v.begin(), v.end());   `       //将v[begin(), end())区间中的元素拷贝给本身。
* `vector(n, elem);`                    //构造函数将n个elem拷贝给本身。
* `vector(const vector &vec);`         //拷贝构造函数
 */
void printVector(vector<int> &v){
    for(vector<int>::iterator p = v.begin();p!=v.end();p++){
        cout<< *p<<" ";
    }
    cout<<endl;
}

void test(){
    vector<int> v;
    for (int i = 0; i <4 ; ++i) {
        v.push_back(i);
    }
    printVector(v);
    vector<int> v2(v.begin(),v.end());
    printVector(v2);

    vector<int> v3(10,100);
    printVector(v3);
    vector<int> v4(v3);
	printVector(v4);
}

int main(){
    test();
}
