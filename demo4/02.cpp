//@Time : 2021-06-17 11:50
//@Author: zxf_要努力
//@File : 02.h
// 访问权限
//三种
// 公共权限 public 成员类内和内外都可以访问
// 保护权限  protected 成员类内可以访问，内外不可以访问 继承时可以使用
// 私有权限 private 成员类内可以访问，内外不可以访问 继承不可以访问
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string m_Nmae;
protected:
    string m_Car;
private:
    int m_Password;
public:
    void func(){
        m_Nmae  = "aaa";
        m_Car  = "aaa";
    }
};


int main(){

}

