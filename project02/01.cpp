//@Time : 2021-06-23 12:10
//@Author: zxf_ҪŬ��
//@File : 01.h
//ʵ�ּ����� ��ͨʵ�ֺͶ�̬ʵ��
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
                cout<<"��������Ϊ0"<<endl;
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
    cout << "�Ӻ�"<<c.getResult("+")<<endl;
    cout << "����"<<c.getResult("-")<<endl;
    cout << "�˺�"<<c.getResult("*")<<endl;
    cout << "����"<<c.getResult("/")<<endl;
}



//��̬ʵ��
//�����������
//��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
class AbstractCalculator{
public:
    virtual int getResult(){
        return 0;
    }
    int num_a;
    int num_b;
};

//�ӷ�������
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
	delete abc;  //�����˼ǵ�����
	abc = new AddCalculator;
	abc->num_a = 10;
    abc->num_b = 10;
    cout << abc->num_a << " + " << abc->num_b << " = " << abc->getResult() << endl;
    delete abc;
}
int main(){

    test02();
}
