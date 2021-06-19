//@Time : 2021-06-19 11:24
//@Author: zxf_要努力
//@File : 01.h
// 类案列
#include <iostream>
using namespace std;
#include "point.h"
#include "cycle.h"

//class point{
//public:
//    int getNX() const {
//        return n_X;
//    }
//
//    void setNX(int nX) {
//        n_X = nX;
//    }
//
//    int getNY() const {
//        return n_Y;
//    }
//
//    void setNY(int nY) {
//        n_Y = nY;
//    }
//
//private:
//    int n_X;
//    int n_Y;
//};
//
//class Cycle{
//public:
//    int getCR() const {
//        return c_R;
//    }
//
//    void setCR(int cR) {
//        c_R = cR;
//    }
//
//    const point &getCP() const {
//        return c_p;
//    }
//
//    void setCP(const point &cP) {
//        c_p = cP;
//    }
//
//private:
//    int c_R;
//    point c_p;
//};

int loc_to_cycle(Cycle c,Point p){
    int r = c.getCR();
    Point p1 = c.getCP();
    int distance = (p1.getNX() - p.getNX()) * (p1.getNX() - p.getNX()) +
            (p1.getNY()-p.getNY()) * (p1.getNY()-p.getNY())  ;

    if(r*r > distance){
        return 0;

    }else if(r*r == distance){
        return 1;
    }else{
        return 2;
    }
}

int main(){
    Point a;
    a.setNX(10);
    a.setNY(0);
    Cycle c;
    c.setCP(a);
    c.setCR(10);
    Point b;
    b.setNX(10);
    b.setNY(11);
    int flag = loc_to_cycle(c,b);
    if (flag == 0){
        cout<<"在圆内"<< endl;
    }else if (flag == 1){
        cout<<"在圆上"<< endl;
    }else{
        cout<<"在圆外"<< endl;
    }
}

