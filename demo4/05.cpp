//@Time : 2021-06-18 23:07
//@Author: zxf_要努力
//@File : 05.h
// 联系 立方体 求面积和体积
//同时使用成员函数和全局函数 判断是否相等
#include <iostream>
using namespace std;



class Club{
public:
    int getMH() const {
        return m_H;
    }

    void setMH(int mH) {
        m_H = mH;
    }

    int getMW() const {
        return m_W;
    }

    void setMW(int mW) {
        m_W = mW;
    }

    int getML() const {
        return m_L;
    }

    void setML(int mL) {
        m_L = mL;
    }

    int areas(){
        return 2*m_L*m_H+2*m_H*m_W+2*m_L*m_W;
    }
    int clubs(){
        return m_H*m_W*m_L;
    }
    bool samebyclass(Club &c){
        if(m_H == c.getMH() and m_L==c.getML() and m_W==c.getMW()){
            return true;
        }else{
            return false;
        }
    }

private:
    int m_H;
    int m_W;
    int m_L;
};

bool getsamebyclass(Club &a,Club &b){
    if(a.getMH()== b.getMH() and a.getML()==b.getML() and a.getMW() == b.getMW()){
        return true;
    }else{
        return false;
    }
}

int main() {
    Club a;
    a.setMH(10);
    a.setML(10);
    a.setMW(100);
    cout << a.areas() << endl;
    cout << a.clubs() << endl;


    Club b;
    b.setMH(10);
    b.setML(10);
    b.setMW(10);
    cout << b.areas() << endl;
    cout << b.clubs() << endl;

    cout<<getsamebyclass(a,b)<<endl;
    cout<< a.samebyclass(b)<<endl;

}
