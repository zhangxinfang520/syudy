//@Time : 2021-06-19 13:05
//@Author: zxf_要努力
//@File : point.h
//
#pragma once
#ifndef C___POINT_H
#define C___POINT_H
#include <iostream>
using namespace std;

class Point{
public:
    int getNX();
    void setNX(int nX);
    int getNY();
    void setNY(int nY);
private:
    int n_X;
    int n_Y;
};


#endif //C___POINT_H
