//@Time : 2021-06-25 9:27
//@Author: zxf_ҪŬ��
//@File : mange_system.h
// ְ������ϵͳ �������
#include "iostream"
#include "workerManager.h"
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main(){
    workerManager workersystem;
    int choice = 0;
    while (true){
        workersystem.Show_menu();
        cout << "����������ѡ��:" << endl;
        cin >> choice;
        switch(choice){
            case 0:
                workersystem.Exit_system();
                break;
            case 1:
                workersystem.Add_Emp();
                break;
            case 2:
                workersystem.show_Emp();
                break;
            case 3:
                workersystem.Del_Emp();
                break;
            case 4:
                workersystem.Mod_Emp();
                break;
            case 5:
                workersystem.Find_Emp();
                break;
            case 6:
                workersystem.Sort_Emp();
                break;
            case 7:
                workersystem.Clean_File();
                break;

            default:
                system("cls");
                break;
        }
    }
    system("pause");
    return 0;
}
