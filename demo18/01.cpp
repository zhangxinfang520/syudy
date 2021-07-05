//@Time : 2021-07-04 17:48
//@Author: zxf_要努力
//@File : 01.h
//STL常用算法
/*
`<algorithm>`是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
`<numeric>`体积很小，只包括几个在序列上面进行简单数学运算的模板函数
`<functional>`定义了一些模板类,用以声明函数对象。

 */

//遍历算法
//* `for_each`     //遍历容器
//* `transform`   //搬运容器到另一个容器中

#include "iostream"
#include "algorithm"
#include <vector>


using namespace std;

//普通函数
void print01(int val){
    cout << val << " ";
}
//函数对象
class print02{
public:
    void operator()(int val){
        cout << val<<" ";
    }
};

void test01(){
    //`for_each(iterator beg, iterator end, _func);  `
    // 遍历算法 遍历容器元素
    // beg 开始迭代器
    // end 结束迭代器
    // _func 函数或者函数对象
    vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
    for_each(v.begin(),v.end(), print01);
	cout << endl;
    for_each(v.begin(),v.end(), print02());
    cout << endl;
}
class print03{
public:
    int  operator()(int val){
        return val;
    }
};
void test02(){
    //搬运容器到另一个容器中
    //`transform(iterator beg1, iterator end1, iterator beg2, _func);`
    //beg1 源容器开始迭代器
    //end1 源容器结束迭代器
    //beg2 目标容器开始迭代器
    //_func 函数或者函数对象
    vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>vTarget; //目标容器
	vTarget.resize(v.size()); // 目标容器需要提前开辟空间
    transform(v.begin(),v.end(),vTarget.begin(), print03());
    for_each(v.begin(),v.end(), print01);

}

int main(){
    test01();
    test02();
}

