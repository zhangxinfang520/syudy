//@Time : 2021-06-24 10:26
//@Author: zxf_要努力
//@File : 03.h
//练习多态
#include "iostream"
using namespace std;

class CPU{
public:
    //抽象计算函数
    virtual void calculate() = 0;
};

class VideoCard{
public:
    virtual void display()=0;

};

class Memory{
public:
    virtual void storage()=0;
};

class Computer{
public:
    Computer(CPU *cpu,VideoCard *vc,Memory *memory){
        m_cpu = cpu;
        m_vc = vc;
        m_memory = memory;
    }
    void work(){
        m_cpu -> calculate();
        m_vc -> display();
        m_memory -> storage();
    }

    ~Computer(){
        if(m_cpu!=NULL){
            cout <<"delete cpu"<<endl;
            delete m_cpu;
            m_cpu=NULL;
        }
        if (m_vc!=NULL){
            cout <<"delete vc"<<endl;
            delete m_vc;
            m_vc = NULL;
        }
        if (m_memory !=NULL){
            cout <<"delete m_memory"<<endl;
            delete m_memory;
            m_memory = NULL;
        }
    }
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_memory;
};

//具体厂商
class InterCPU:public CPU{
public:
    virtual void calculate(){
        cout <<"interCPU do work"<<endl;
    }
};

class InterVideoCard : public VideoCard{
public:
    virtual void display(){
        cout << "InterVideoCard do work" <<endl;
    }
};

class InterMemory :public Memory{
public:
    virtual void storage(){
        cout << "InterMemory do word"<<endl;
    }
};

class LenovoCPU:public CPU{
public:
    virtual void calculate(){
        cout <<"LenovoCPU do work"<<endl;
    }
};

class LenovoVideoCard : public VideoCard{
public:
    virtual void display(){
        cout << "LenovoVideoCard do work" <<endl;
    }
};

class LenovoMemory :public Memory{
public:
    virtual void storage(){
        cout << "LenovoMemory do word"<<endl;
    }
};

void test(){
    CPU *cpu = new InterCPU();
    VideoCard *vc = new InterVideoCard();
    Memory *memory = new InterMemory();
    Computer *pc = new Computer(cpu,vc,memory);
    pc->work();
    cout<< "the first computer"<<endl;
    delete pc;
    cout << "----------"<<endl;
    Computer *pc2 = new Computer(new LenovoCPU(),
                                 new LenovoVideoCard(),new LenovoMemory());
    pc2 -> work();
    delete pc2;
    cout<< "the second computer"<<endl;

    Computer *p3 = new Computer(new InterCPU(),new LenovoVideoCard(),new InterMemory());
    p3 -> work();
    delete p3;
}

int main(){
    test();
}