//@Time : 2021-06-29 14:12
//@Author: zxf_要努力
//@File : myArray.h
//
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray{
public:
    MyArray(int capacity){
        //cout<<"这是构造函数"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    //拷贝构造
    MyArray(const MyArray &arr){
        //cout<<"这是拷贝构造函数"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < this->m_Size ; ++i) {
            //如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
			// 普通类型可以直接= 但是指针类型需要深拷贝
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    int getCapacity(){
        return this->m_Capacity;
    }
    int getSize(){
        return this->m_Size;
    }
    //重载= 操作符  防止浅拷贝问题
    MyArray& operator=(MyArray& arr){
            if(this->pAddress !=NULL){
                //cout<<"这是operator函数"<<endl;
                delete[] this->pAddress;
                this->m_Capacity = 0;
                this->m_Size = 0;
            }
            this->m_Capacity = arr.m_Capacity;
            this->m_Size = arr.m_Size;
            this->pAddress = arr.pAddress;
        for (int i = 0; i <this->m_Size ; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    T& operator[](int index){
        return this->pAddress[index];
    }
    //尾插法
    void Push_back(const T &val){
        if(this->m_Size == this->m_Capacity){
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size ++;
    }
    //尾删法
    void Pop_back(){
        if(this->m_Size==-1){
            return;
        }
        this->m_Size --;
    }
    ~MyArray(){
        if(this->pAddress!=NULL){
            //cout<<"这是析构函数"<<endl;
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Size = 0;
            this->m_Capacity = 0;
        }
    }


private:
    T * pAddress; //指向一个堆空间 这个空间存储真正的数据
    int m_Capacity;//容量
    int m_Size;//大小
};
