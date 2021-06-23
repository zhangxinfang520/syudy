//@Time : 2021-06-23 16:13
//@Author: zxf_ҪŬ��
//@File : 02.h
// ��̬����ϰ
#include "iostream"
using namespace std;

class Base{
public:
    virtual void Boil()=0;
    virtual void Brew()=0;
    virtual void PourIncup()=0;
	virtual void PutSomething() = 0;
	void MakeDrink(){
	    Boil();
	    Brew();
	    PourIncup();
	    PutSomething();
	}
};

class Coffee:public Base{
public:
    virtual void Boil(){
        cout << "��ũ��ɽȪ!" << endl;
    };
    virtual void Brew() {
        cout << "���ݿ���!" << endl;
    };
    virtual void PourIncup() {
        cout << "�����ȵ��뱭��!" << endl;
    };
	virtual void PutSomething() {
	    cout << "����ţ��!" << endl;
	};
};

class Tea:public Base{
public:
    virtual void Boil(){
        cout << "��ũ��ɽȪ!" << endl;
    };
    virtual void Brew() {
        cout << "���ݲ�!" << endl;
    };
    virtual void PourIncup() {
        cout << "����ˮ���뱭��!!" << endl;
    };
	virtual void PutSomething() {
	    cout << "�������!" << endl;
	};
};

void DoWork(Base* ba){
    ba->MakeDrink();
}

void test(){

    DoWork(new Coffee);
    cout << "--------------" << endl;
    DoWork(new Tea);
}

int main(){
    test();
    system("pause");
}
