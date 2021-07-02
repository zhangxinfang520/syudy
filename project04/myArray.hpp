//@Time : 2021-06-29 14:12
//@Author: zxf_ҪŬ��
//@File : myArray.h
//
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray{
public:
    MyArray(int capacity){
        //cout<<"���ǹ��캯��"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    //��������
    MyArray(const MyArray &arr){
        //cout<<"���ǿ������캯��"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < this->m_Size ; ++i) {
            //���TΪ���󣬶��һ�����ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ��� ���� ���Ǹ�ֵ��
			// ��ͨ���Ϳ���ֱ��= ����ָ��������Ҫ���
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    int getCapacity(){
        return this->m_Capacity;
    }
    int getSize(){
        return this->m_Size;
    }
    //����= ������  ��ֹǳ��������
    MyArray& operator=(MyArray& arr){
            if(this->pAddress !=NULL){
                //cout<<"����operator����"<<endl;
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
    //β�巨
    void Push_back(const T &val){
        if(this->m_Size == this->m_Capacity){
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size ++;
    }
    //βɾ��
    void Pop_back(){
        if(this->m_Size==-1){
            return;
        }
        this->m_Size --;
    }
    ~MyArray(){
        if(this->pAddress!=NULL){
            //cout<<"������������"<<endl;
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Size = 0;
            this->m_Capacity = 0;
        }
    }


private:
    T * pAddress; //ָ��һ���ѿռ� ����ռ�洢����������
    int m_Capacity;//����
    int m_Size;//��С
};
