//@Time : 2021-06-19 13:09
//@Author: zxf_要努力
//@File : cycle.h
//
#pragma once
#ifndef C___CYCLE_H
#define C___CYCLE_H

#include <iostream>
using namespace std;
#include "point.h"

class Cycle{
public:
    int getCR();
    void setCR(int cR);
    Point getCP();
    void setCP(Point cP);
private:
    int c_R;
    Point c_p;
};


#endif //C___CYCLE_H
