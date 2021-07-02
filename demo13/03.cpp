//@Time : 2021-06-30 11:09
//@Author: zxf_要努力
//@File : 03.h
// vector 嵌入 vector
#include "iostream"
#include <vector>
#include "algorithm"
#include "string"
using namespace std;

void test() {
    vector< vector<int> > p;
    vector<int> pp1;
    vector<int> pp2;
    vector<int> pp3;
    vector<int> pp4;

    for (int i = 0; i < 4; ++i) {
        pp1.push_back(i + 1);
        pp2.push_back(i + 2);
        pp3.push_back(i + 3);
        pp4.push_back(i + 4);
    }
    p.push_back(pp1);
    p.push_back(pp2);
    p.push_back(pp3);
    p.push_back(pp4);
    //遍历数据
    for (vector<vector<int> >::iterator v = p.begin(); v!=p.end(); v++) {
        for (vector<int>::iterator vv = (*v).begin(); vv!=(*v).end() ; vv++) {
            cout<<*vv<<" ";
        }
        cout<<endl;
    }
}

int main(){
    test();
}