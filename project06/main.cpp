//@Time : 2021-07-05 11:54
//@Author: zxf_ҪŬ��
//@File : main.h
//�ݽ�����
#include "speechManager.h"

int main(){
    //srand((unsigned int) time(NULL));
    SpeechManager sm;
    int choice;
    while(true){
        sm.show_Menu();
        cout << "����������ѡ�� " << endl;
        cin >> choice;
        switch(choice){
            case 1://��ʼ����
//                for(map<int,Speaker>::iterator it=sm.m_Speaker.begin(); it!=sm.m_Speaker.end();it++){
//                    cout<< " id " <<(*it).first<<endl;
//                    cout<< " id " <<(*it).second.m_Name<<endl;
//                    cout<< " id " <<(*it).second.m_Score[0]<<endl;
//                }
                sm.startSpeech();
                break;
            case 2://�鿴��¼
                sm.showRecord();
                break;
            case 3://��ռ�¼
                sm.clearRecord();
                break;
            case 0://�˳�ϵͳ
                sm.exitSystem();
                break;
            default:
                system("cls");
                break;
        }
    }

}

