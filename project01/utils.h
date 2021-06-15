//
// Created by lenovo on 2021-06-15.
//

#ifndef C___UTILS_H
#define C___UTILS_H
#include <string>
#define MAX 1000

struct Person {
    std::string m_Name;
    int m_Sex;
    int m_Age;
    std::string m_Phone;
    std::string m_Addr;
};

struct Addressbooks{
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(Addressbooks *abs);
void showPerson(Addressbooks *abs);
int isExist(Addressbooks *abs,std::string name);
void deletePerson(Addressbooks *abs);
void findPerson(Addressbooks *abs);
void modifyPerson(Addressbooks *abs);
void clearPerson(Addressbooks *abs);
void showMenu();


#endif //C___UTILS_H
