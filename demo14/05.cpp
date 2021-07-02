//@Time : 2021-07-02 23:33
//@Author: zxf_要努力
//@File : 05.h
//对vector中的数据的存取操作
#include "iostream"
#include <vector>
#include "algorithm"

using namespace std;

/*
 **函数原型：**
* `at(int idx); `     //返回索引idx所指的数据
* `operator[]; `      //返回索引idx所指的数据
* `front(); `         //返回容器中第一个数据元素
* `back();`           //返回容器中最后一个数据元素
 */
void test(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "v1的第一个元素为： " << v.front() << endl;
	cout << "v1的最后一个元素为： " << v.back() << endl;
}

int main(){
    test();
}
