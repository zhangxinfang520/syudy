//@Time : 2021-07-04 16:45
//@Author: zxf_要努力
//@File : 03.h
//* 实现四则运算
//* 其中negate是一元运算，其他都是二元运算
#include "iostream"
#include "algorithm"
#include <vector>
#include <functional>
using namespace std;

//negate
void test01()
{
	negate<int> n;
	cout << n(50) << endl;
}

//plus
void test02()
{
	plus<int> p;
	cout << p(10, 20) << endl;
}
//关系运算

//* `template<class T> bool equal_to<T>`                    //等于
//* `template<class T> bool not_equal_to<T>`            //不等于
//* `template<class T> bool greater<T>`                      //大于
//* `template<class T> bool greater_equal<T>`          //大于等于
//* `template<class T> bool less<T>`                           //小于
//* `template<class T> bool less_equal<T>`               //小于等于

//逻辑运算
//* `template<class T> bool logical_and<T>`              //逻辑与
//* `template<class T> bool logical_or<T>`                //逻辑或
//* `template<class T> bool logical_not<T>`              //逻辑非

void test03(){
    vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin();it!= v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(),  v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main() {

	test01();
	test02();
    test03();
	system("pause");

	return 0;
}
