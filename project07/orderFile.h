//@Time : 2021-07-07 17:04
//@Author: zxf_要努力
//@File : orderFile.h
//
#pragma once
#ifndef C___ORDERFILE_H
#define C___ORDERFILE_H
#include<iostream>
#include "fstream"
using namespace std;
#include <map>
#include "globalFile.h"

class OrderFile {
public:

	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
	map<int, map<string, string>> m_orderData;

	//预约记录条数
	int m_Size;
};


#endif //C___ORDERFILE_H
