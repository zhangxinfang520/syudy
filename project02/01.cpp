//@Time : 2021-06-23 12:10
//@Author: zxf_要努力
//@File : 01.h
//实现计算器 普通实现和多态实现
#include "iostream"

using namespace std;

class Calculator{
public:
    int getResult(string oper){
        if(oper=="+"){
            return num_a + num_b;
        }else if(oper=="-"){
            return num_a - num_b;
        }else if(oper=="*"){
            return num_a * num_b;
        }else if(oper == "/"){
            if(num_b==0){
                cout<<"除数不能为0"<<endl;
                return 0;
            }
            return num_a / num_b;
        }
    }
    int num_a;
    int num_b;
};

void test01(){
    Calculator c;
    c.num_a = 10;
    c.num_b = 10;
    cout << "加号"<<c.getResult("+")<<endl;
    cout << "减号"<<c.getResult("-")<<endl;
    cout << "乘号"<<c.getResult("*")<<endl;
    cout << "除号"<<c.getResult("/")<<endl;
}



//多态实现
//抽象计算器类
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstractCalculator{
public:
    virtual int getResult(){
        return 0;
    }
    int num_a;
    int num_b;
};

//加法计算器
class AddCalculator :public AbstractCalculator{
public:
    int getResult(){
        return num_a + num_b;
    }
};

class SubCalculator:public AbstractCalculator{
public:
    int getResult(){
        return num_a - num_b;
    }
};

class MulCalculator :public AbstractCalculator{
public:
    int getResult(){
        return num_a * num_b;
    }
};

void test02(){
    AbstractCalculator *abc = new MulCalculator;
    abc->num_a = 10;
    abc->num_b = 10;
    cout << abc->num_a << " * " << abc->num_b << " = " << abc->getResult() << endl;
	delete abc;  //用完了记得销毁
	abc = new AddCalculator;
	abc->num_a = 10;
    abc->num_b = 10;
    cout << abc->num_a << " + " << abc->num_b << " = " << abc->getResult() << endl;
    delete abc;
}
int main(){

    test02();
}
