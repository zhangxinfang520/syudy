//@Time : 2021-06-23 16:13
//@Author: zxf_要努力
//@File : 02.h
// 多态的练习
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
        cout << "煮农夫山泉!" << endl;
    };
    virtual void Brew() {
        cout << "冲泡咖啡!" << endl;
    };
    virtual void PourIncup() {
        cout << "将咖啡倒入杯中!" << endl;
    };
	virtual void PutSomething() {
	    cout << "加入牛奶!" << endl;
	};
};

class Tea:public Base{
public:
    virtual void Boil(){
        cout << "煮农夫山泉!" << endl;
    };
    virtual void Brew() {
        cout << "冲泡茶!" << endl;
    };
    virtual void PourIncup() {
        cout << "将茶水倒入杯中!!" << endl;
    };
	virtual void PutSomething() {
	    cout << "加入枸杞!" << endl;
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
