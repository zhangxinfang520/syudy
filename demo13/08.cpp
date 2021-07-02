//@Time : 2021-06-30 13:56
//@Author: zxf_要努力
//@File : 08.h
//字符串比较
#include "iostream"
#include <string>
using namespace std;
/*
字符串比较是按字符的ASCII码进行对比
= 返回   0
> 返回   1
< 返回  -1
 * `int compare(const string &s) const; `  //与字符串s比较
* `int compare(const char *s) const;`      //与字符串s比较
 */
//字符串比较
void test01()
{

	string s1 = "hello";
	string s2 = "aello";

	int ret = s1.compare(s2);

	if (ret == 0) {
		cout << "s1 等于 s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 大于 s2" << endl;
	}
	else
	{
		cout << "s1 小于 s2" << endl;
	}

}

int main() {

	test01();

	system("pause");

	return 0;
}
