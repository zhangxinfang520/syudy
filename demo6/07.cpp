//@Time : 2021-06-20 17:04
//@Author: zxf_ҪŬ��
//@File : 07.h
// ��ָ�� ���Ե��ó�Ա����
#include "iostream"
//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
using namespace std;
class Person{
public:
    int age;
    void ShowClassName(){
        cout<<"����person��"<<endl;
    }

    void Show(){
        if (this==NULL){
            return;
        }
        cout << age << endl;
    }
};

void test(){
    Person * p =NULL;

    p->ShowClassName();
    p->Show();

}
int main(){
    test();
}

