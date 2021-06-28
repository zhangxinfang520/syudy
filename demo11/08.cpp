//@Time : 2021-06-28 15:36
//@Author: zxf_要努力
//@File : 08.h
//类模板与继承
#include "iostream"
using namespace std;
#include <string>
#include<typeinfo>

template<class T>
class Base{
    T m;
};
//最笨的写法
class Son1:public Base<int>{

};
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};
void test02()
{
	Son2<int, char> child1;
}

int main() {


	test02();

	system("pause");

	return 0;
}