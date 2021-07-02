//@Time : 2021-07-02 9:49
//@Author: zxf_要努力
//@File : 04.h
//
#include "iostream"
#include <vector>
#include "algorithm"
using namespace std;

/*
 * `push_back(ele);`                                         //尾部插入元素ele
* `pop_back();`                                                //删除最后一个元素
* `insert(const_iterator pos, ele);`        //迭代器指向位置pos插入元素ele
* `insert(const_iterator pos, int count,ele);`//迭代器指向位置pos插入count个元素ele
* `erase(const_iterator pos);`                     //删除迭代器指向的元素
* `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
* `clear();`                                                        //删除容器中所有元素
 */

void printVector(vector<int> &a){
    for (vector<int>::iterator v = a.begin(); v!= a.end() ; v++) {
        cout << *v<<" ";
    }
    cout<<endl;
}

void test(){
    vector<int> v;
    for(int i=0;i<4;i++){
        v.push_back(i);
    }
    printVector(v);
    v.pop_back();
    v.insert(v.begin(),3);
    printVector(v);
    v.insert(v.begin(),2,4);
    printVector(v);

    v.erase(v.begin());
    printVector(v);
    v.erase(v.begin(),v.end());
    v.clear();
    printVector(v);

}

int main(){
 test();
}

