//@Time : 2021-06-22 10:15
//@Author: zxf_要努力
//@File : 01.h
// 继承的基本语法
#include "iostream"
#include <string>
using namespace std;
class Java{
public:
    void head(){
        cout<<"我是java头部"<<endl;
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
        cout<<"我是python头部"<<endl;
    }
    void foot(){
        cout<<"i am python foot"<<endl;
    }
    void left(){
        cout<<"i am python left"<<endl;
    }
};


//编写公共类
class pageBase{
public:
    void head(){
        cout<<"我是公共头部"<<endl;
    }
    void foot(){
        cout<<"我是公共foot"<<endl;
    }
    void left(){
         cout<<"我是公共left"<<endl;
    }
};

class CPP:public pageBase{
public:
    void conent(){
         cout<<"我是cpp 特有的内容"<<endl;
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
