//@Time : 2021-07-02 23:33
//@Author: zxf_ҪŬ��
//@File : 05.h
//��vector�е����ݵĴ�ȡ����
#include "iostream"
#include <vector>
#include "algorithm"

using namespace std;

/*
 **����ԭ�ͣ�**
* `at(int idx); `     //��������idx��ָ������
* `operator[]; `      //��������idx��ָ������
* `front(); `         //���������е�һ������Ԫ��
* `back();`           //�������������һ������Ԫ��
 */
void test(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "v1�ĵ�һ��Ԫ��Ϊ�� " << v.front() << endl;
	cout << "v1�����һ��Ԫ��Ϊ�� " << v.back() << endl;
}

int main(){
    test();
}
