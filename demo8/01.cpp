//@Time : 2021-06-22 10:15
//@Author: zxf_ҪŬ��
//@File : 01.h
// �̳еĻ����﷨
#include "iostream"
#include <string>
using namespace std;
class Java{
public:
    void head(){
        cout<<"����javaͷ��"<<endl;
    }
    void foot(){
        cout<<"i am java foot"<<endl;
    }
    void left(){
        cout<<"i am java left"<<endl;
    }
};
class Python{
public:
    void head(){
        cout<<"����pythonͷ��"<<endl;
    }
    void foot(){
        cout<<"i am python foot"<<endl;
    }
    void left(){
        cout<<"i am python left"<<endl;
    }
};


//��д������
class pageBase{
public:
    void head(){
        cout<<"���ǹ���ͷ��"<<endl;
    }
    void foot(){
        cout<<"���ǹ���foot"<<endl;
    }
    void left(){
         cout<<"���ǹ���left"<<endl;
    }
};

class CPP:public pageBase{
public:
    void conent(){
         cout<<"����cpp ���е�����"<<endl;
    }
};

void test(){
    Java j;
    j.head();
    j.left();
    j.foot();
    cout<<"______________"<<endl;
    Python p;
    p.head();
    p.left();
    p.foot();
    CPP cpp;
    cpp.left();
    cpp.head();
    cpp.foot();
    cpp.conent();
}

int main(){
    test();
}
