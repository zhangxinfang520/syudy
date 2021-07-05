//@Time : 2021-07-05 9:40
//@Author: zxf_要努力
//@File : 03.h
//常用排序算法
#include "iostream"
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> create_date(){
    vector<int> v ;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(5);
    return v;
}

void printV(vector<int> &nums){
    for(int num:nums){
        cout << num << " ";
    }
    cout <<endl;
}

void myPrint(int val)
{
	cout << val << " ";
}

void test01(){
    //排序
    vector<int> v = create_date();
    printV(v);
    sort(v.begin(), v.end());
     printV(v);
     for_each(v.begin(), v.end(),myPrint);
     //从大到小排序
     sort(v.begin(), v.end(),greater<int>());
     printV(v);
}

void test02(){
    //random_shuffle  指定范围内的元素随机调整次序
    //设计随机种子
    srand((unsigned int) time(NULL));
    vector<int> v = create_date();
    printV(v);
    sort(v.begin(), v.end());
    printV(v);
    random_shuffle(v.begin(), v.end());
    printV(v);
}

void test03(){
    //* 两个容器元素合并，并存储到另一容器中
    //merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 容器元素合并，并存储到另一容器中
    // 注意: 两个容器必须是**有序的**
    // beg1   容器1开始迭代器
    // end1   容器1结束迭代器
    // beg2   容器2开始迭代器
    // end2   容器2结束迭代器
    // dest    目标容器开始迭代器

    vector<int> v1 = create_date();
    vector<int> v2 = create_date();
    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    merge(v1.begin(), v1.end(),v2.begin(), v2.end(),v3.begin());
    printV(v3);

}

void test04(){
    //区间反转
    vector<int > v = create_date();
    printV(v);
    reverse(v.begin(), v.end());
    printV(v);
}

int main(){
    //test01();
    //test02();
    //test03();
    test04();
}

