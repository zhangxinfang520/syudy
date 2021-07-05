//@Time : 2021-07-05 10:44
//@Author: zxf_要努力
//@File : 05.h
// 常用的生成算法
#include "iostream"
#include <algorithm>
#include <numeric>

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

void test01(){
    //计算区间内 容器元素累计总和
    //- accumulate`      // 计算容器元素累计总和
    //- `fill`                 // 向容器中添加元素
    vector<int> v = create_date();
    int total = accumulate(v.begin(),v.end(),0);
    cout <<total << endl;
}
void test02(){
    //填充指定元素
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end(),100);
    printV(v);
}

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test03(){
    //集合常用操作

    //set_intersection        // 求两个容器的交集
    //set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 求两个集合的交集
    // **注意:两个集合必须是有序序列**
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器
    vector<int> v1 =create_date();
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);

    vector<int> target;
    target.resize(min(v1.size(),v2.size()));

    vector<int>::iterator it = set_intersection(v1.begin(),
                                                v1.end(),v2.begin(), v2.end(),target.begin());
    for_each(target.begin(), it, myPrint());
	cout << endl;
}

void test04(){
    //求两个集合的并集
    //`set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 求两个集合的并集
    // **注意:两个集合必须是有序序列**
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取两个容器的和给目标容器开辟空间
	vTarget.resize(v1.size() + v2.size());

	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd =
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
	//- 求并集的两个集合必须的有序序列
    //- 目标容器开辟空间需要**两个容器相加**
    //- set_union返回值既是并集中最后一个元素的位置
}

void test05(){
    //求两个集合的差集
    //`set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
    // 求两个集合的差集
    // **注意:两个集合必须是有序序列**
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取两个里面较大的值给目标容器开辟空间
	vTarget.resize( max(v1.size() , v2.size()));

	//返回目标容器的最后一个元素的迭代器地址
	cout << "v1与v2的差集为： " << endl;
	vector<int>::iterator itEnd =
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;


	cout << "v2与v1的差集为： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
	//- 求差集的两个集合必须的有序序列
    //- 目标容器开辟空间需要从**两个容器取较大值**
    //- set_difference返回值既是差集中最后一个元素的位置
}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
}



