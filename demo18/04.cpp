//@Time : 2021-07-05 10:15
//@Author: zxf_要努力
//@File : 04.h
//常用的拷贝函数
#include "iostream"
#include <vector>
#include <algorithm>

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
   //容器内指定范围的元素拷贝到另一容器中
   //copy(iterator beg, iterator end, iterator dest)
   // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
   // beg  开始迭代器
   // end  结束迭代器
    // dest 目标起始迭代器
    vector<int> v1 = create_date();
    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(),v2.begin());
    printV(v2);
}

void test02(){
    //将容器内指定范围的旧元素修改为新元素
    //`replace(iterator beg, iterator end, oldvalue, newvalue);  `
    // 将区间内旧元素 替换成 新元素
    // beg 开始迭代器
    // end 结束迭代器
    // oldvalue 旧元素
    // newvalue 新元素
    vector<int> v =create_date();
    printV(v);
    replace(v.begin(), v.end(),1,7);
    printV(v);
}

class ReplaceGreator3{
public:
    bool operator()(int val){
        return val > 3;
    }
};

void test03(){
    vector<int> v = create_date();
    printV(v);
    replace_if(v.begin(), v.end(),ReplaceGreator3(),1);
    printV(v);

};

void test04(){
    //互换两个容器的元素
    //`swap(container c1, container c2);  `
    // 互换两个容器的元素
    // c1容器1
    // c2容器2
    vector<int> v = create_date();
    vector<int> v2;
    v2.push_back(10);
    printV(v);
    printV(v2);
    swap(v,v2);
    printV(v);
    printV(v2);
}

int main(){
    //test01();
    //test02();
    //test03();
    test04();
}

