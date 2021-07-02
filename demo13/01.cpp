//@Time : 2021-06-30 9:32
//@Author: zxf_要努力
//@File : 01.h
// 容器算法 学习
#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;

void func(int val){
    cout << val <<endl;
}

int main(){
    //创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
    vector<int> v;
    //向容器存放数据
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //遍历
    //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
	//v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	//第一种
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
    //vector<int>::iterator pBegin = v.begin();
    //vector<int>::iterator pEnd = v.end();
    //while(pBegin!=pEnd){
       // cout<<*pBegin << endl;
        //pBegin ++;
    //}
    //第二种
    for (vector<int>::iterator p=v.begin();  p!=v.end() ; p++) {
        cout<<*p<<endl;
    }
    cout <<"__________"<<endl;
    //第三种 使用STL提供标准遍历算法  头文件 algorithm
    for_each(v.begin(),v.end(),func);

}

