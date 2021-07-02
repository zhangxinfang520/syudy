//@Time : 2021-06-29 11:51
//@Author: zxf_要努力
//@File : Person.h
//
#pragma once
#include "iostream"
using namespace std;
#ifndef C___PERSON_H
#define C___PERSON_H

template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age);
	void showPerson();
    T1 m_Name;
	T2 m_Age;
};


#endif //C___PERSON_H
