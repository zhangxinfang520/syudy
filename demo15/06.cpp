//@Time : 2021-07-03 11:23
//@Author: zxf_要努力
//@File : 06.h
//deque的排序


#include "iostream"
#include <algorithm>
#include <deque>
using namespace std;

/*
 sort(iterator beg, iterator end)`  //对beg和end区间内元素进行排序
 */

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

void test(){
    deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	printDeque(d);
	sort(d.begin(), d.end());
	printDeque(d);
}

int main(){
    test();
}
