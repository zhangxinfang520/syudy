//
// Created by lenovo on 2021-06-15.
//
#include <iostream>
#include "utils.h"
#include "pro01.h"


int start(){
    int select = 0;
    // 创建通讯录
    Addressbooks aps;
    aps.m_Size = 0;
    while(true){
        showMenu();
        std::cin >> select;
        std::cout << select;
        switch(select)
        {
            case 1:
                addPerson(&aps);
                break;
            case 2:
                showPerson(&aps);
                break;
            case 3:
                deletePerson(&aps);
                break;
            case 4:
                findPerson(&aps);
                break;
            case 5:
                modifyPerson(&aps);
                break;
            case 6:
                clearPerson(&aps);
                break;
            case 0:
               std::cout << "欢迎下次使用" << std::endl;
               system("pause");
               return 0;
               break;
            default:
                break;
        }
    }
}