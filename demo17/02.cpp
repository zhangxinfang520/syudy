//@Time : 2021-07-04 16:22
//@Author: zxf_要努力
//@File : 02.h
//谓词概念
//* 返回bool类型的仿函数称为**谓词**
//* 如果operator()接受一个参数，那么叫做一元谓词
//* 如果operator()接受两个参数，那么叫做二元谓词
#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

struct GreatFive{
    bool operator()(int val){
        return  val > 5;
    }
};

void test01(){
    vector<int> v;
    for (int i = 0; i <10 ; ++i) {
        v.push_back(i);
    }
    vector<int>::iterator it= find_if(v.begin(),v.end(),GreatFive());
    if(it ==v.end()){
        cout << "no found" <<endl;
    } else{
        cout << " found" << *it<<endl;
    }
}

class MyCompare{
public:
    bool operator()(int num1,int num2){
        return num1 > num2;
    }
};

void test02(){
    //二元谓词 就是有两个参数
    vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	//默认从小到大
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<< *it <<" ";
    }
    cout << endl;
    sort(v.begin(),v.end(),MyCompare());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<< *it <<" ";
    }
    cout<< endl;


}

int main(){
    test01();
    test02();
}

