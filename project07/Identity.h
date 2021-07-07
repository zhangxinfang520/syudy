//@Time : 2021-07-06 15:13
//@Author: zxf_要努力
//@File : Identity.h
//
#pragma once
#include "iostream"
using namespace std;
#ifndef C___IDENTITY_H
#define C___IDENTITY_H
class Identity{
public:
    //操作菜单
    virtual void operMenu() = 0;
    string m_Name;
    string m_Pwd;
};

#endif //C___IDENTITY_H
